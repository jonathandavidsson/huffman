/*
Authors:    Eric Matei, Jonathan Davidsson
Date:       10-03-25

Description: 
This file provides functions for creating and managing a Huffman trie,
including node creation, tree construction from a frequency table and memory deallocation.
It also includes a function for comparing nodes based on frequency,
wich is used for priority queue operations.
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman_trie.h"
#include "huffman_table.h"
#include "pqueue.h"

#define BYTES_MAX 256


/**
* @brief Function that is called for comparing two
* priorities.
*
* If val1 is the first value and val2 the second, the following must
* be returned: \n
* \> 0 if val1 \> val2 \n
* \< 0 if val1 \< val2 \n
* 0 if val1 = val2
*/
int compare_nodes(void *a, void *b) //vafna är detta
{
    HuffmanNode *node_a = (HuffmanNode*)a;
    HuffmanNode *node_b = (HuffmanNode*)b;
 
    if (node_a->frequency < node_b->frequency) return -1;
    if (node_a->frequency > node_b->frequency) return 1;
    
    return 0;
}


HuffmanNode *create_huffman_node(char symbol, int frequency)
{
	HuffmanNode *node = malloc(sizeof(HuffmanNode));

	node->symbol = symbol;
	node->frequency = frequency; 
	node->left = NULL;
	node->right = NULL;

	return node;
}


HuffmanNode *create_huffman_trie(Frequency *frequencies, int num_chars) //Detta måste inspekteras...
{
  pqueue *pq = pqueue_empty(compare_nodes);
    for (int i = 0; i < num_chars; i++)
    {
        HuffmanNode *node = create_huffman_node((char)frequencies[i].byte, frequencies[i].frequency);
        pqueue_insert(pq, node);
    }
    
    while (!pqueue_is_empty(pq))
    {
        HuffmanNode *left = pqueue_inspect_first(pq);
        pqueue_delete_first(pq);
        
        if(pqueue_is_empty(pq))
        {
            pqueue_kill(pq);
            return left;
        }
        
        HuffmanNode *right = pqueue_inspect_first(pq);
        pqueue_delete_first(pq);
        
        HuffmanNode *internal = create_huffman_node('\0', left->frequency + right->frequency);
        internal->left = left;
        internal->right = right;
        pqueue_insert(pq, internal);
    }
    
    HuffmanNode *root = pqueue_inspect_first(pq);
    pqueue_kill(pq);
    return root;
}


void free_huffman_trie(HuffmanNode* root) 
{
    if (root == NULL)
	{
		return;
	}
    
    free_huffman_trie(root->left);
    free_huffman_trie(root->right);
    free(root);
}


void print_huffman_trie(HuffmanNode *node, int depth)
{
	if (node == NULL)
	{
		return;
	}

	for (int i = 0 ; i < depth ; i++)
	{
		printf(" ");
	}

	if (node->symbol != '\0')
	{
		printf("Leaf: '%c' (frequency: %d)\n", node->symbol, node->frequency);
	}

	else 
	{
		printf("Internal Node (frequency: %d)\n", node->frequency);
	}

	print_huffman_trie(node->left, depth + 1);
	print_huffman_trie(node->right, depth + 1);
}
