#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <stdlib.h>
/********************************************************************************
 * The main program that makes use of the functions defined in functions.c in 
 * order to create a simple substitution cipher in C.
 *
 * This approach only makes use of one substitution table that can be used to
 * either encrypt or decrypt a message.
 *
 * @author Ron Rounsifer
 * @version 0.04
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
		FILE *fin_file = fopen(fin, "r");
		FILE *fout_file = fopen(fout, "w");

		// remove duplicate letters from keyword
		remove_duplicates(keyword, strlen(argv[2]));

		// create encrypt or decryption tables
		if (option == 'e')
		{
			init_encryption_array(keyword, substitution_table);
			process_input(fin_file, fout_file, substitution_table, option);
		} 
		else if (option == 'd') 
		{
			init_encryption_array(keyword, substitution_table);
			process_input(fin_file, fout_file, substitution_table, option);
		}

		free(substitution_table);
	}
	return 0;
}
