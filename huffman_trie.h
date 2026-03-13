#ifndef HUFFMAN_TRIE_H
#define HUFFMAN_TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freq_table.h"

#define BYTES_MAX 256

/**
 * @defgroup Huffman Trie
 *
 * @brief A file that provides a Huffman trie.
 *
 * This file provides functions for creating and managing a Huffman trie.
 * It manages node creation and tree construction from a frequency table.
 * It also includes a function for comparing nodes based on frequency.
 *
 * @authors Eric Matei & Jonathan Davidsson
 * @since 10-03-25
 *
 * @{
 */

/**
 * @brief A structure that represents a node in a Huffman trie.
 *
 * This structure is used to represents a node in a Huffman trie.
 */
typedef struct HuffmanNode
{
	int frequency;  /**< The frequency of the symbol in the input data. */
	char symbol;	/**< The character symbol represented by this node. */
	struct HuffmanNode *left, *right;	/**< Pointers to the left and right child. */
} HuffmanNode;

/** 
 * @brief A function that compares nodes.
 *
 * This function compares two Huffman nodes by their frequency values.
 *
 * @param a		A pointer to the first Huffman node.
 * @param b 	A pointer to the second Huffman node.
 * @return		-1 if the first node has a lower frequency,
 *				    1 if the first node has a higher frequency,
 *				    0 if both nodes have the same frequency.
 *
 * @see pqueue_insert, pqueue_delete_first
 */
int compare_nodes(void *a, void *b);

/**
 * @brief A function that creates nodes.
 *
 * This function creates a huffman node and initializes its symbol and frequency.
 *
 * @param symbol	The character symbol represented by the node.
 * @param frequency	The frequency of the symbol in the input data.
 * @return			A pointer to the nwely created Huffman node.
 */
HuffmanNode *create_huffman_node(char symbol, int frequency);

/** 
 * @brief A function that creates a Huffman trie.
 *
 * This function creates and builds a Huffman trie.
 *
 * @param frequencies	A pointer to an array of 'Frequency' structures representing
 *						the symbols and their frequencies.
 * @param num_chars		The number of unique characters.
 * @return 				A pointer to the root of the newly built Huffman trie.
 *
 * @see create_huffman_node, free_huffman_trie, compare_nodes
 */
HuffmanNode *create_huffman_trie(Frequency *frequencies, int num_chars);

 /**
  * @brief A function that destroys the Huffman trie.
  *
  * This function frees all nodes in the Huffman trie.
  * Its the users responsibility to use this function for memory deallocation.
  *
  * @param root		A pointer to the root of the Huffman trie.
  * @return	-
  *
  * @see create_huffman_trie, create_huffman_node
  */
void free_huffman_trie(HuffmanNode* root);

/**
 * @brief A function that prints out the Huffman trie.
 *
 * This function prints out the Huffman trie.
 *
 * @param node		A pointer to the current node in the Huffman trie.
 * @param depth		The depth of the current node.
 * @return -
 *
 * @see create_huffman_trie, free_huffman_trie
 */
void print_huffman_trie(HuffmanNode *node, int depth);

/** 
 * @}
 */
#endif
