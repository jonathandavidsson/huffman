#ifndef FREQ_TABLE_H
#define FREQ_TABLE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @defgroup Frequency Table
 *
 * @brief A module that implements functions for creating, populatin and managing a frequency table.
 *
 * This file provides functionalities for creating and initializing a frequency table,
 * scanning a file and get byte frequencies, sorting the frequency table from highest to lowest frequency,
 * printing the frequency of each byte and destruction of the frequency table.
 *
 * @authors	Eric Matei & Jonathan Davidsson
 * @since	10-03-25
 *
 * @{
 */

/**
 * @brief A structure to represent a frequency table.
 *
 * This structure is used to represent a frequency table using the byte value
 * and the frequency of the byte.
 */
typedef struct
{
	int frequency;		/**< The number of occurences of the byte. */
	unsigned char byte; 	/**< The byte (character) being counted. */

} Frequency;

/**
* @brief Creates a frequency table.
*
* This function creates and innitializes a frequency table.
*
* @param	-
* @return	A pointer to to the created and initialized frequency table.
*
* @see freq_frequency, destroy_freq
*/
Frequency *freq_create();

/**
 * @brief Updates the frequency table.
 *
 * This function uptades the frequency table based on byte occurences in a file.
 *
 * @param freq_table	An array of 'Frequency' representing the frequency table.
 * @param FILE0			The path to the file whose byte frequencies need to be counted.
 * @return				-
 *
 * @see freq_create, freq_compare_bytes, print_frequency
 */
void freq_frequency(Frequency freq_table[], const char *FILE0);

/**
 * @brief Sorts the frequency table in descending order of frequency.
 *
 * This function sorts the frequency table using the bulle sort algorithm,
 * arranging the byte frequencies from highest to lowest.
 *
 * @param freq_table	An array of 'Frequency' representing the frequency table.
 * @return 				-
 *
 * @see freq_create, freq_frequency, print_frequency
 */
void freq_compare_bytes(Frequency freq_table[]);

/**
 * @brief Prints out the frequency table.
 *
 * This function goes through the frequency table and prints each byte
 * along with it's corresponding frequency.
 *
 * @param freq_table 	An array of 'Frequency' representing the frequency table.
 * @return				-
 *
 * @see freq_create, freq_frequency, freq_compare_bytes
 */
void print_frequency(Frequency freq_table[]);

/**
 * @brief Destroys the frequency table.
 *
 * This function destroys the frequency table.
 * It's the users responsibilty to use this function for memory deallocation.
 *
 * @param freq_table	An array of 'Frequency' representing the frequency table.
 */
void destroy_freq(Frequency freq_table[]);

/** 
 * @}
 */
#endif
