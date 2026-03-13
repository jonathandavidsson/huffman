/*
Authors:	Eric Matei & Jonathan Davidsson
Date:		10-03-25
Description:
This file contains the implamantation of the function that is responsible for encoding a file
based on a given Huffman table. The function reads the input file byte by byte, converts each byte
into its corresponding Huffman code, and writes the encoded data to an output file. It uses a
bit buffer to store the encoded data in memory, wich is later written to the output file in byte-sized chunks.

*/

#include <stdio.h>
#include <stdlib.h>
#include "encode.h"
#include "bit_buffer.h"
#include "huffman_table.h"

int encode_file(HuffmanCode *huffman_table, FILE *file1, FILE *file2, char *read_file)
{
	if(!file1 || !file2 || !huffman_table)
	{
		return -1;
	}

	bit_buffer *encoded_buffer = bit_buffer_empty(); //Skapar en tom bitbuffer för att lagra den kodade bitströmmen.
	int character;
	int total_bytes_read = 0;    //Spårar antalet tecken lästa från filen.
	int total_bytes_written = 0; //Spårar antalet bytes skrivna i den kodade filen.

	while((character = fgetc(file1)) != EOF) //Kör loop medans den inte läst hela filen, alltså då den inte är i EOF.
	{
		total_bytes_read++;

		char *symbol_code = huffman_table[(unsigned char)character].code; //Läser in vilken symbol som ska encodas.

		if(symbol_code != NULL)
		{
			for(int i = 0 ; symbol_code[i] != '\0' ; i++) 
			{
				bit_buffer_insert_bit(encoded_buffer, (symbol_code[i] == '1') ? 1 : 0); //...
			}
		}
	}

	char *eot_code = huffman_table[4].code; 
    if(eot_code != NULL)
    {
        for(int i = 0; eot_code[i] != '\0'; i++)
        {
            bit_buffer_insert_bit(encoded_buffer, (eot_code[i] == '1') ? 1 : 0);
        }
    } //Lägger till en slut-markör så att dekodningsfunktionen vet när den ska sluta.


	while (bit_buffer_size(encoded_buffer) >= 8) //När bit buffern innehåller minst 8 bits konverteras de till en byte och skrivs över i file2
	{
		char output_byte = bit_buffer_remove_byte(encoded_buffer);
		fputc(output_byte, file2);
		total_bytes_written++;
	}

	if(bit_buffer_size(encoded_buffer) > 0)
	{
		while(bit_buffer_size(encoded_buffer) < 8)
		{
			bit_buffer_insert_bit(encoded_buffer, 0);
		}

		char output_byte = bit_buffer_remove_byte(encoded_buffer);
		fputc(output_byte, file2);
		total_bytes_written++;
	} //Om det finns kvar bitar som inte fyller en hel bytem fylls det med 0 tills vi har 8 bitar, sedan skrivs den in i file2.
	
	printf("\n%d bytes read from %s\n", total_bytes_read, read_file);
	printf("%d bytes used in encoded form.\n", total_bytes_written);

	bit_buffer_free(encoded_buffer); //Frigör bit buffern.

	return 0;
}
