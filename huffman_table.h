#ifndef HUFFMAN_TABLE_H
#define HUFFMAN_TABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "huffman_trie.h"

/** 
 * @defgroup Huffman Table
 *
 * @brief Functions for generating and managing a Huffman encoding table.
 *
 * This file provides functions to generate a Huffman code table.
 *
 * @authors Eric Matei & Jonathan Davidsson
 * @since 10-03-25
 *
 * @{
 */

/** 
 * @brief A structure to represent a Huffman table.
 *
 * This structre is used to represent a Huffman table.
 *
 */
typedef struct
{
	unsigned char symbol;	/**< The character being encoded. */
	char *code;		/**< A pointer to the Huffman code string. */
}HuffmanCode;

/**
 * @brief A function that generates Huffman codes.
 *
 * This function is used to generates Huffman codes from a Huffman trie.
 *
 * @param root	A pointer to the root of the Huffman trie.
 * @param depth The current depth of the traversal.
 * @param code 	Temporary character array used to construct Huffman codes.
 * @param huffman_table	A array where the computed Huffman codes will be stored.
 * @return -
 *
 * @see create_Huffman_table, free_Huffman_table
 */
void get_huffman_code(HuffmanNode *root, int depth, char *code, HuffmanCode huffman_table[]);

/**
 * @brief A function that creates the Huffman table.
 *
 * This function is used to create the Huffman table.
 *
 * @param root	A pointer to the root of the Huffman trie.
 * @return 		A pointer to the populated Huffman table.
 *
 * @see get_huffman_code, free_Huffman_table
 */
HuffmanCode *create_Huffman_table(HuffmanNode *root);

/**
 * @brief A function that destroys the Huffman table.
 *
 * This function destroys the Huffman table.
 * Its the users responsibility to use this function for memory deallocation.
 *
 * @param huffman_table A pointer to the Huffman table to be destroyed.
 * @return	-
 *
 * @see get_huffman_code, create_Huffman_table
 */
void free_Huffman_table(HuffmanCode *huffman_table);

/**
 * @}
 */
#endif