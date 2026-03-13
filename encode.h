#ifndef ENCODE_H
#define ENCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bit_buffer.h"
#include "huffman_table.h"

/**
 * @defgroup Encode
 *
 * @brief A function for encoding.
 *
 * This file contains the function responsible for encoding a file based on
 * a given Huffman table.
 *
 * @authors	Eric Matei & Jonathan Davidsson
 * @since	10-03-25
 *
 * @{
 */

/**
 * @brief Encoding function.
 *
 * This function encodes a file based on a given Huffman table.
 *
 * @param huffman_table	A pointer to the Huffman table.
 * @param file0			The input file to be encoded.
 * @param file1			The output file to store the encoded result.
 * @param read_file		The input file name.
 * @return 				0 if encoding was successful.
 * @return				-1 if there was an error with any of the input parameters.
 */
int encode_file(HuffmanCode *huffman_table, FILE *file0, FILE *file1, char *read_file);

/**
 * @}
 */
#endif
