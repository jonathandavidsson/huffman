#include <stdio.h>
#include <stdlib.h>
#include "freq_table.h"
/*
Authors:	Jonathan Davidsson and Eric Matei
Date: 		10-03-25
Description:
This file implements functions for creating, updating, sorting and printing
a frequency table used in Huffman coding. The frequency table tracks occurences
of each byte in an input file and can be used for constructing a Huffman trie.
*/

#define BYTES_MAX 256


Frequency *freq_create()
{
	Frequency *freq_table = malloc(BYTES_MAX * sizeof(Frequency));

	for(int i = 0; i < BYTES_MAX; i++)//Initiera frekvenstabellen.
	{
		freq_table[i].byte = i;			
		freq_table[i].frequency = 0;
	}

	freq_table[4].byte = 4;     //EOF byte.
	freq_table[4].frequency = 1; 

	return freq_table;
}


void freq_frequency(Frequency freq_table[], const char *FILE0)
{
	FILE *file = fopen(FILE0, "r"); //Öppnar filen i 'read' läge.

	int byte;
	
	while((byte = fgetc(file)) != EOF) //Läser varje byte i filen och uppdaterar varje bytes frekvens eftersom.
	{
		freq_table[byte].frequency++;
	}

	fclose(file); //Stäng filen.
	
}


void freq_compare_bytes(Frequency freq_table[]) 
{
	int i, j;

    Frequency temp;
	//Bubble sort, för att sortera frekvenstabellen, egentligen onödigt.
    for (i = 0 ; i <= BYTES_MAX - 1 ; i++) 
	{
        for (j = 0 ; j <= BYTES_MAX - i - 1 ; j++) 
		{
            if (freq_table[j].frequency < freq_table[j + 1].frequency) 
			{
                temp = freq_table[j];
                freq_table[j] = freq_table[j + 1];
                freq_table[j + 1] = temp;
            }
        }
    }
}


void print_frequency(Frequency freq_table[])
{
	for (int i = 0 ; i < BYTES_MAX ; i++)
	{
		printf("Byte: %d, Frequency: %d \n", freq_table[i].byte, freq_table[i].frequency); //Skriver ut frekvensen för alla bytes.
	}
}


void destroy_freq(Frequency freq_table[])
{
	free(freq_table); //Frigör frekvenstabellen. 
}
