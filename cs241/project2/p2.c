#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>
/********************************************************************************
 * The main program that makes use of the functions defined in functions.c in 
 * order to create a simple substitution cipher in C.
 *
 * @author Ron Rounsifer
 * @version 0.01
 ********************************************************************************/

/********************************************************************************
 * Main entry point of the program.
 ********************************************************************************/
int main(int argc, char **argv) 
{
	if (argc != 5)
	{
		printf("usage: ./p2 [option] [keyword] [file in] [file out]\n");
	} else {

		char *substitution_table = malloc(sizeof(char) * 26);
		char option = *argv[1];
		char *keyword = argv[2];
		char *fin = argv[3];
		char *fout = argv[4];

		// remove duplicate letters from keyword
		remove_duplicates(keyword, strlen(argv[2]));
		printf("%s\n", keyword);	

		// create encrypt or decryption tables
		if (option == 'e')
		{
			init_encrypt_array(keyword, substitution_table);
		} 
		else if (option == 'd') 
		{
			init_decrypt_array(keyword, substitution_table);
		}

		free(substitution_table);
	}
	return 0;
}
