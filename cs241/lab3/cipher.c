#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt(char ch, int k);

/**
 * A Caesar cipher implementation in C.
 */
int main(int argc, char* argv[])
{  
	int choice;
	char* key;
	int key_length;
	int* key_ints;
	int char_value;
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}

	choice = atoi(argv[1]);
	key = argv[2];
	key_length = (int) strlen(key);

	key_ints = malloc(sizeof(int) * key_length); //TODO modify this for dynamic allocation

	
	/* Maps the inputted string to their corresponding int representation 
	 * into the key_ints array.
	 *
	 * helpful ascii code modulos:
	 * 	capitals -> % 65
	 * 	lowercase -> % 97
	 * */
	for (int i = 0; i < key_length; ++i)
	{
		if (choice == 1) // encrypt option
		{
			if (islower(key[i]))
			{
			 	char_value = key[i] % 97;
			 	key_ints[i] = char_value;

			} else if (isupper(key[i]))
			{
				char_value = key[i] % 65;
				key_ints[i] = char_value;

			}	
		} else if (choice == 2) { // decrypt option
			if (islower(key[i]))
			{
			 	char_value = -(key[i] % 97);
			 	key_ints[i] = char_value;

			} else if (isupper(key[i]))
			{
				char_value = -(key[i] % 65);
				key_ints[i] = char_value;

			}	
		}
	}

    	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}

	int index = 0;
	char new_char;
	int n = 0;
	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		index = n % key_length;
		new_char = encrypt(ch, key_ints[index]);
		fprintf(fout, "%c", new_char);
	}

	fclose(fin);
	fclose(fout);
	
	free(key_ints);

	return 0;
}


/**
 * Encrypts the given character by the list of char that are inputted.
 */
char encrypt(char ch, int k)
{
	char new_char;
	if ( k < 0 )
		k = k + 26;
	if ( isupper(ch) ) // handle uppercase letters
		new_char = (ch - 'A' + k) % 26 + 'A';
	else if ( islower(ch) ) // handle lowercase letters
		new_char =  (ch - 'a' + k) % 26 + 'a';
	else // handle everytihng else (special chars)
		new_char = ch;
	return new_char;
}
