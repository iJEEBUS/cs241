/****************************************************************************************
 * Header class for all of the functions that are used to create a substituation cipher
 * in the language of C.
 *
 * @author Ron Rounsifer
 * @version 0.04
 ****************************************************************************************/
#include <stdio.h>

/* remove duplicate chars from a string */
void remove_duplicates(char *word, int word_length);

/* create the encrypt array with correct cipher letters given the key */
void init_encryption_array(char *key, char *encrypt);

/* process data from input file and write result to output file */
void process_input(FILE *fin, FILE *fout, char *substitute, char option);
