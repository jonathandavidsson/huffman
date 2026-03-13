/*
Athours:	Eric Matei & Jonathan Davidsson
Date:		10-03-25
Description:
This program implements a command-line utility for Huffman encoding and decoding.
It takes input files containing text data and preforms a frequency analysis on the data.
Based on the frequency analysis, it constructs a Huffman trie and generates a Huffman table.
Encoding compresses data based on the Huffman coding and stores the result in a specified output file.
Decoding decompresses data using the Huffman trie and writes the result to a specified output file.
*/

#include <stdio.h>
#include <stdlib.h>
#include "huffman_trie.h"
#include "huffman_table.h"
#include "freq_table.h"
#include "encode.h"
#include "decode.h"
#include "bit_buffer.h"

#define BYTES_MAX 256

/* Internal function declarations. */

/*
Option menu. 
Description:
This function prints out a menu in terminal if the arguments is invalid.
Input:	-
Output:	-
*/
void print_options()
{
	printf("> huffman\n");
	printf("USAGE:\n");
	printf("huffman [OPTION] [FILE0] [FILE1] [FILE2]\n");
	printf("Options:\n");
	printf("-encode encodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
	printf("-decode decodes FILE1 according to frequence analysis done on FILE0. Stores the result in FILE2\n");
}

/* 
Validates arguments. 
Description:
This function checks if the correct number of arguments is provided and
verifies that the first argument is either "-encode" or "-decode".
Input: argc		The number of arguments.
Input: argv		The argument vector containing file names.
Output: 		0 if the argument are valid, 1 otherwise.
*/
int validate_argument(int argc, char *argv[])
{
	if((strcmp(argv[1], "-encode") != 0 && strcmp(argv[1], "-decode") != 0) || argc != 5)
	{
		print_options();
		return 1;
	}

	return 0;
}

/*
Validates files.
Description:
This function attempts to open two files specified in the command-line
arguments to ensure they exist and can be accessed.
Input: argc	The number of arguments.
Input: argv	The argument vector containing file names.
Output: 	0 if both files are accessible, 1 otherwise.
*/
int validate_file(int argc, char *argv[])
{

	FILE *file0 = fopen(argv[2], "rb");
	if(!file0)
	{
		printf("ERROR: Error opening file: %s. \n", argv[2]);

		return 1;
	}
	else
	{
		printf("File: %s opened correctly.\n", argv[2]);
	}

	fclose(file0);

	FILE *file1 = fopen(argv[3], "rb");
	if(!file1)
	{
		printf("Error opening file: %s.\n", argv[3]);

		return 1;
	}
	else
	{
		printf("File: %s opened correctly.\n", argv[3]);
	}
	
	fclose(file1);

	return 0;
}

int main(int argc, char *argv[])
{
	if(validate_argument(argc, argv) == 1)
	{
		return 0;
	}
	validate_file(argc, argv);

	Frequency *freq_table = freq_create();
	
	freq_frequency(freq_table, argv[2]);

	freq_compare_bytes(freq_table);

	printf("\nFrequency-table:\n\n");
	print_frequency(freq_table);

	HuffmanNode *huffman_trie = create_huffman_trie(freq_table, BYTES_MAX);

	printf("\nHuffman-trie:\n\n");
	print_huffman_trie(huffman_trie, 0);

	printf("\nHuffman-table and Huffman-codes:\n\n");
	HuffmanCode *huffman_table = create_Huffman_table(huffman_trie);

	char *read_file = argv[3];
	char *encoded_file = argv[4];

	if(strcmp(argv[1], "-encode") == 0)
	{
		FILE *file1 = fopen(argv[3], "r");
		FILE *file2 = fopen(argv[4], "w");
	
		encode_file(huffman_table, file1, file2, read_file);

		fclose(file1);
		fclose(file2);
	}

	else if(strcmp(argv[1], "-decode") == 0)
	{
		FILE *file1 = fopen(argv[3], "r");
		FILE *file2 = fopen(argv[4], "w");
	
		decode_file(huffman_trie, file1, file2, encoded_file);
	
		fclose(file1);
		fclose(file2);
	}

	free_Huffman_table(huffman_table);
	free_huffman_trie(huffman_trie);
	destroy_freq(freq_table);
	
	return 0;

}
