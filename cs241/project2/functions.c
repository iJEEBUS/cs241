/**************************************************************************************
 * The implementations of the functions that are needed in order to create a simple
 * substitution cipher in C.
 *
 * This contains three functions:
 * 	remove_duplicates - runs through and removed duplicate letters in a word
 * 	init_encryption_array - creates an array that can be used to encrypt / decrypt 
 * 				a message
 *	process_input - given a file to read from and a file to write to, this encodes
 *			or decodes character by character before writing the new 
 *			character to the file
 *
 * @author Ron Rounsifer
 * @version 0.04
 **************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


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
 * Populate the encryption array with the appropriate cipher letters according to the
 * given key.
 *
 * @params char[] - the given key
 * @params char[] - the encryption array
 **************************************************************************************/
void init_encryption_array(char *key, char *encrypt)
{
	char alphabet[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	int encrypt_index = 0;

	// insert keyword into beginning of encryption array
	for (int i = 0; i < 26; ++i)
	{
		if ((i < strlen(key)) & (key[i] != '\n'))
		{
			encrypt[i] = key[i];
			encrypt_index++;
		} 
	}

	// append unused letters from the backwards alphabet
	// to the encryption array
	for (int j = 0; j < 26; ++j) 
	{
		if (strchr(encrypt, alphabet[j]) == NULL)
		{
			if (encrypt_index < 26)
			{
				encrypt[encrypt_index++] = alphabet[j];	
			}
		} 
	}
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
void process_input(FILE *fin, FILE *fout, char *substitute, char option)
{
	char ch;
	char new_char;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char l_alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	int sub_index;
	int lowercase = 0;

	if (option == 'e') // encoding logic
	{
		
		while (fscanf(fin, "%c", &ch) != EOF)
		{
			// encrypt the char
			if (ch > 90)
			{
				lowercase = 1;
			}
			sub_index = toupper(ch) - 65;
			new_char = substitute[sub_index];

			// write the new char to a file
			if ((ch == ' ') | (ch == ',') | (ch == '.') | (ch == '\n'))
				fwrite(&ch, sizeof(ch), 1, fout);
			else
			{
				if (lowercase)
				{
					new_char = tolower(substitute[sub_index]);
					fwrite(&new_char, sizeof(new_char), 1, fout);
					lowercase = 0;
				} else {
					fwrite(&new_char, sizeof(new_char), 1, fout);
				}
			}
					
		}
	} 
	if (option == 'd')  // decoding logic
	{

		char *match_ptr;

		// as long as there is data to decode, execute this code
		while (fscanf(fin, "%c", &ch) != EOF)
		{
			// lowercase check
			if (ch > 90)
				lowercase = 1;
	
			// special character check 
			if ( (ch == ' ') | (ch == ',') | (ch == '.') | (ch == '\n'))
				fwrite(&ch, sizeof(ch), 1, fout);
			else
			{
				// get a pointer to a match (if one exists) 
				match_ptr = strchr(substitute, toupper(ch));
				
				// write to file only if an actual match is found
				if (match_ptr != 0)
				{
					// use pointer arithmetic to find the index of the decoded letter
					sub_index = ((long) match_ptr - (long) substitute);
					
					if (lowercase)
					{
						new_char = l_alphabet[sub_index];
						fwrite(&new_char, sizeof(new_char), 1, fout);
						lowercase = 0;
					}
					else{
						new_char = alphabet[sub_index];
						fwrite(&new_char, sizeof(new_char), 1, fout);
					}
				}
			}
		}
	} 
}
