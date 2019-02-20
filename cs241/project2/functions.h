/****************************************************************************************
 * Header class for all of the functions that are used to create a substituation cipher
 * in the language of C.
 *
 * @author Ron Rounsifer
 * @version 0.01
 ****************************************************************************************/
#include <stdio.h>

/* remove duplicate chars from a string */
void remove_duplicates(char *word, int word_length);

/* search first num chars for a target char */
int target_found(char *charArray, int num, char target);

/* create the encrypt array with correct cipher letters given the key */
void init_encrypt_array(char *key, char *encrypt);

/* create the decrypt array with correct substitute letters based on encrypted array */
void init_decrypt_array(char *encrypt, char *decrypt);

/* process data from input file and write result to output file */
void process_input(FILE *fin, FILE *fout, char *substitute);
