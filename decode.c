/*
Authors:	Eric Matei & Jonathan Davidsson¨
Date:		10-03-25
Description:
This file contains the function for decoding a file that was encoded.
The function reads the encoded data from an input file, traverses the Huffman trie
according to the bits in the data, and writes the decoded symbols to the output file.
The function uses a bit buffer to manage the bits of the endoded file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decode.h"
#include "bit_buffer.h"
#include "huffman_trie.h"
#include "huffman_table.h"

void decode_file(HuffmanNode *huffman_trie_root, FILE *file1, FILE *file2, char *encoded_file)
{
	if(!file1 || !file2 || !huffman_trie_root)
	{
		return;
	}

	bit_buffer *encoded_buffer = bit_buffer_empty(); //Skapar bit buffer.
	int byte; //Variabel för inlästa bytes

	while((byte = fgetc(file1)) != EOF) //Kör medans filen inte är i end of file.
	{
		bit_buffer_insert_byte(encoded_buffer, (char)byte); //Lägger in lästa bytes i bit buffern.
	}

	HuffmanNode *current_node = huffman_trie_root; //Börja vid huffman-triens rot.

	while(bit_buffer_size(encoded_buffer) > 0) //Kör medans bit buffer är > 0
	{
		int bit = bit_buffer_remove_bit(encoded_buffer); 

		current_node = (bit == 0) ? current_node->left : current_node->right; //Kollar om bit är = 0 och navigerar så pass antingen höger eller vänster.

		if(current_node->left == NULL && current_node->right == NULL) // If-sats för att kolla om vi är i ett löv, då har vi dekrypterat en symbol.
		{
			if(current_node->symbol == 4) //Kollar om vi är i EOF och i så fall break.
			{
				break;
			}
			fputc(current_node->symbol, file2); //Symbolen skriv in i file2

			current_node = huffman_trie_root; //Tilldelas huffman roten för att börja traversera igen.

		}
	}

	printf("\n%s decoded succesfully.\n", encoded_file);

	bit_buffer_free(encoded_buffer); //Frigör bitbuffern.
}
