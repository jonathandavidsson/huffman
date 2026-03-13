/*
Authors: 	Eric Matei & Jonathan Davidsson
Date:		10-03-25
Description:
This file provides functions to generate a Huffman code table from a Huffman trie,
store symbol-to-code mappings and deallocate memory when the table is no longer needed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman_trie.h"
#include "huffman_table.h"

#define BYTES_MAX 256

void get_huffman_code(HuffmanNode *root, int depth, char *code, HuffmanCode huffman_table[])
{
	if(root == NULL) //Null-check
	{
		return;
	}

	if(root->left == NULL && root->right == NULL) //Om det är ett löv så har vi hela koden klar.
	{
		code[depth] = '\0'; //Stäng strängen

		huffman_table[(unsigned char)root->symbol].symbol = root->symbol;
		huffman_table[(unsigned char)root->symbol].code = malloc(strlen(code) + 1); //Allokerar minne för symbolens huffman-kodning.

		strcpy(huffman_table[(unsigned char)root->symbol].code, code); //Kopierar huffmankodningen till tabellen.
	
		printf("Character: (%c), Frequency: (%d), Huffman-code: (%s) \n", root->symbol, root->frequency, huffman_table[(unsigned char)root->symbol].code);

		return;
	}

	//I if-satserna kollar den om vi går höger eller vänster och beroende på vad så lägger den till antingen en nolla eller etta.
    if(root->left) 
    {
        code[depth] = '0'; 
        get_huffman_code(root->left, depth + 1, code, huffman_table);
    }
    
    if(root->right) 
    {
        code[depth] = '1'; 
        get_huffman_code(root->right, depth + 1, code, huffman_table);
    }
    
    code[depth] = '\0'; //Glömde ta bort denna rad, funkade just nu för det påverkar inte funktionaliteten på programmet.

}

HuffmanCode *create_Huffman_table(HuffmanNode *root)
{
	HuffmanCode *huffman_table = malloc(BYTES_MAX * sizeof(HuffmanCode));
	
	for(int i = 0 ; i < BYTES_MAX ; i++) //Initierar huffman-tabellen.
	{
		huffman_table[i].symbol = (unsigned char)i;
		huffman_table[i].code = NULL;
	}

	char code[BYTES_MAX] = {0}; //Array för att lagra huffmankod, denna kopieras sedan in i huffmantabellen.

	get_huffman_code(root, 0, code, huffman_table);

	return huffman_table;	
}

void free_Huffman_table(HuffmanCode *huffman_table)
{
	for(int i = 0 ; i < BYTES_MAX ; i++)
	{
		free(huffman_table[i].code);
	}

	free(huffman_table);
}
