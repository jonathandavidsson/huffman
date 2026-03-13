/*!
* \mainpage Huffman
*
* \subsection Introduction
* In this text we will go over how our implementation of a Huffman-coding program is built, how it works, what datatypes were used, how the files
* were divided and how it's used. 
* 
* \subsection Functionality
* This is a Huffman-coding program which in short reads a given text-file, counts each byte in the text-file and its frequency. And later give each byte a
* seperate binary code depending on frequency, where the highest frequency recieves the most optimal code, ensuring the most effective binary code of the
* text-file. The user can either choose -decode or -encode when running the program, which alters what the program does.
* This is more thoroughly explained in section: How to use, but in short the program will either encode a file with the help of the huffman-codes generated
* or decode a file that was previously encoded with -encode.
*
* \subsection How to use
* This program can be used by two different prompts: 
* ./huffman -encode FILE0.txt FILE1.txt FILE2.txt
* ./huffman -decode FILE0.txt FILE2.txt FILE3.txt

* The choice of prompts depends on what the user is trying to achieve,
* ./huffman -encode FILE0.txt FILE1.txt FILE2.txt will read FILE0 and create a frequency table based on the file, it will then encode the other given text-file
* based from the huffman-code generated from FILE0, lastly it will write out the generated code of the text-file in FILE2.
*
* ./huffman -decode FILE0.txt FILE2.txt FILE3.txt will read FILE0 to get the huffman-codes for the decoding of the file. It will then read the previously encoded
* file containing the full code to be decoded. And decodes the file and prints in in FILE3.txt.
* 
* \subsection Data Types
* This program uses many different data types, some of which we have written ourselves and others that were already implemented.
*
* These were the already implemented data types used in our solution:
* Priority queue, (pqueue.c)
* Bit buffer, (bit_buffer.c)
* List, (list.c)
* 
* These data types were not implemented and were created during the development of the program:
* Frequency table, (freq_table.c)
* Huffman trie, (huffman_trie.c)
* Huffman table, (huffman_table.c)
*
* Frequency Table:
* Our implementation of the frequency table uses a struct called Frequency, which contains: an 'int frequency' that stores the frequency of each
* byte that is read, and an 'unsigned char byte' that stores which byte is being represented. The frequency table is then used in our implementation 
* of the Huffman trie.
*
* Huffman Trie:
* Our implementation of the Huffman trie uses a struct called HuffmanNode, which contains: an 'int frequency' that stores the frequency/the total
* frequency of bytes in a node. A 'char symbol' that stores the character represented in this node. A 'HuffmanNode *left' and 'HuffmanNode *right',
* which are pointers to the node’s left and right children. In the actual implementation of the Huffman trie, we use the priority queue data type 
* to easily make correct insertions into the Huffman trie, where bytes with the lowest frequency get the highest 'priority' and are therefore 
* inserted first in the trie.
*
* Huffman Table:
* Our implementation of the Huffman table uses a struct called HuffmanCode, which contains: an 'unsigned char symbol' that stores the symbol that is being
* encoded. A 'char *code' which is a pointer to the Huffman code string. The implementation uses the previously mentioned Huffman-trie to generate the 
* Huffman codes by traversing the trie. 
*
*
* \subsection Structure
* This program uses many different files in its use, this section will explain which files are used in our implementation and a small description
* of each files contents.
* 
* (Each .c file have a .h counterpart file)
*
* freq_table.c
* This file contains our implementation of a frequency table.
*
* huffman_trie.c
* This file contains our implementation of a huffman trie.
*
* huffman_table.c
* This file contains our implementation of a huffman table.
*
* huffman.c
* This file contains our 'main' function which is essentially what runs the entire program and calls each individual function.
* 
* encode.c
* This file contains our 'encode' function which encodes a given file with given huffman-codes and prints the encoded version of
* the file in a new file.
*
* decode.c
* This file contains our 'decode' function which decodes the previously encoded file by reading it, and later using the huffman-codes to decode it
* and print the decoded version in a new file.
*
* pqueue.c
* This function contains the already implemented priority queue.
*
* list.c
* This file contains the already implemented list.
*
* bit_buffer.c
* This file contains the already implemented bit buffer.
*
*
* \subsection Authors
*
* Jonathan Davidsson
* dv24jdn@ad.umu.se
* Eric Matei
* dv24emi@ad.umu.se
*
*/
