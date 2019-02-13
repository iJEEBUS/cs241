/**************************************************************************************
 * The implementations of the functions that are needed in order to create a simple
 * substitution cipher in C.
 *
 * @author Ron Rounsifer
 * @version 0.01
 **************************************************************************************/
#include <stdio.h>

/**************************************************************************************
 * Removes duplicate letters that occur in a string, leaving only the 
 * first occurrence in the word.
 *
 * @params char - the word to modify
 * @returns char* - pointer to word without duplicate letters
 **************************************************************************************/
char* remove_duplicates(char word[])
{
	// TODO
	return NULL;
}

/**************************************************************************************
 * Searches the first num  characters in a string for a specified target
 * character.
 *
 * @params char[] - the string to search
 * @params int - the number of letters to search
 * @params char - the target character
 *
 * @returns int - non-zero value if found, 0 if not found
 **************************************************************************************/
int target_found(char charArray[], int num, char target)
{
	// TODO
	return 0;
}

/**************************************************************************************
 * Populate the encryption array with the appropriate cipher letters according to the
 * given key.
 *
 * @params char[] - the given key
 * @params char[] - the encryption array
 **************************************************************************************/
void init_encrypt_array(char key[], char encrypt[])
{
	// TODO
}

/**************************************************************************************
 * Populate the decryption array with the with the appropriate substitution letters
 * based on the encrypte array.
 *
 * @params char[] - the encryption array
 * @params char[] - the decryption array
 **************************************************************************************/
void init_decrypt_array(char encrypt[], char decrypt[])
{
	// TODO
}

/**************************************************************************************
 * Process the data from the input file and output the result into the output file.
 * For encryption: pass encrypt array to substitute parameter
 * For decryption: pass decrypt array to substitute parameter
 *
 * @params FILE - input file
 * @params FILE - output file
 * @params char - the encrypt/decrypt array 
 **************************************************************************************/
void process_input(FILE *fin, FILE *fout, char substitute[])
{
	// TODO
}
