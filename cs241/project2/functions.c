/**************************************************************************************
 * The implementations of the functions that are needed in order to create a simple
 * substitution cipher in C.
 *
 * @author Ron Rounsifer
 * @version 0.01
 **************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**************************************************************************************
 * Removes duplicate letters that occur in a string, leaving only the 
 * first occurrence in the word.
 *
 * @params char - the word to modify
 * @params int - the length of the keyword
 * @returns char* - pointer to word without duplicate letters
 **************************************************************************************/
void remove_duplicates(char *word, int word_length)
{
	// create temporary memory, fill with unique letters, set new string
	// and free temporary memory
	char *temp = malloc(sizeof(char) * word_length);
	int temp_index = 0;
	for (int i = 0; i < word_length; ++i)
	{
		if (strchr(temp, word[i]) == NULL)
		{
		 temp[temp_index] = word[i];
		 temp_index++;
		}
	}

	for (int j = 0; j < word_length; ++j)
	{
		if (j < (temp_index+1))
		{
			word[j] = temp[j];
		} else {
			word[j] = '\n';
		}
	}
	word = temp;
	free(temp);
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
int target_found(char *charArray, int num, char target)
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
void init_encrypt_array(char *key, char *encrypt)
{
	char *msg = "Creating encryption array.";
	printf("%s\n", msg);

	char *alphabet = malloc(sizeof(char) * 26);

	// TODO Create the encryption array
	// populate alphabet arr
	char letter = 'Z';
	for (int i = 65; i < 91; ++i)
	{
		alphabet[i] = letter;
		letter--;

		printf("%d\n", alphabet[i]);
	}

	for (int j = 0; j < 26; ++j)
	{
		if (j < strlen(key) & key[j] != '\n')
		{
			encrypt[j] = key[j];
		} else {
		
		}
	}

	free(alphabet);
}

/**************************************************************************************
 * Populate the decryption array with the with the appropriate substitution letters
 * based on the encrypte array.
 *
 * @params char[] - the encryption array
 * @params char[] - the decryption array
 **************************************************************************************/
void init_decrypt_array(char *encrypt, char *decrypt)
{
	char *msg = "Creating decryption array.";
	printf("%s\n", msg);
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
void process_input(FILE *fin, FILE *fout, char *substitute)
{
	// TODO
}
