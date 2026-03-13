#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman_table.h"
#include "huffman_trie.h"
#include "bit_buffer.h"

/**
 * @defgroup Decode
 *
 * @brief Function for decoding a file that was encoded.
 *
 * This file contains the function responsible for decoding a file based on a given Huffman trie.
 *
 * @authors	Eric Matei & Jonathan Davidsson
 * @since 	10-03-25
 *
 * @{
 */

/**
 * @brief Decoding function.
 *
 * This function decodes a file based on a given Huffman trie.
 *
 * @param huffman_trie_root	The root of the Huffman trie.
 * @param file1				The input file containing encoded data.
 * @param file2				The output file where the decoded data will be written.
 * @param encoded_file		The encoded file name.
 * @return					-
 */
void decode_file(HuffmanNode *huffman_trie_root, FILE *file1, FILE *file2, char *encoded_file);

/**
 * @}
 */
#endif
