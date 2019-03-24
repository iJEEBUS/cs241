#include "coding.h"

/* encode characters into unsigned long integers and save the encoded integers
 * in a file.
 * charaters are read from a file.
 * infile: input file, contains plaintext.
 * outfile: output file, where encoded integers are saved.
 * return 0 on success, and 1 on failure.
 */
int encode(FILE * infile, FILE * outfile)
{
	// return if either of the file pointers is NULL
	if(infile == NULL || outfile == NULL)
		return 1;

	// Need to determine the size of unsigned long
	int ul_size = sizeof(unsigned long int);
	// Need to determine the size of char
	int ch_size = sizeof(unsigned char);

	// number holder and char holder
	unsigned long int ul_holder = 0;
	unsigned char ch_holder;

	int n = 0, ch_per_ul = ul_size / ch_size;
	int ch_size_bits = ch_size * 8;

	/* do the coding */
	while(fscanf(infile, "%c", &ch_holder) != EOF)
	{
		ul_holder = ul_holder | ch_holder;
		
		if (n < (ch_per_ul - 1))
			ul_holder = ul_holder << ch_size_bits;

		if ((++n) == ch_per_ul)
		{
			//done this int, save it & initialize for next one
			fprintf(outfile, "%lu, ", ul_holder);
			n = 0;
			ul_holder = 0;
		}
	}
	
	/* pad the last unsigned long integer with '\0' */
	if(ul_holder != 0)
	{
		ch_holder = '\0';
		while(1)
		{
			ul_holder = ul_holder | ch_holder;
			if((++n) >= ch_per_ul)
			{
				fprintf(outfile, "%lu, ", ul_holder);
				n = 0;
				ul_holder = 0;
				break;
			}
			else
			{
				ul_holder = ul_holder << ch_size_bits;
			}
		}
	}
	
	return 0;
}

/* decode unsigned long integers into chars and save them to another file.
 * infile: input file, contains unsigned long integers.
 * outfile: output file, used to save decoded characters (plain text).
 * return 0 on success and 1 on failure.
 */
int decode(FILE * infile, FILE * outfile)
{

	// check if files exist
	if (infile == NULL || outfile == NULL)
		return 1;


	int char_per_ul = sizeof(unsigned long int) / sizeof(char);	
	unsigned long int ul_holder = 0;
	unsigned char ch_holder;
	unsigned char buffer[char_per_ul];
	int reverse_count = char_per_ul - 1;
	int n = 0;

	// read from the file
	while (fscanf(infile, "%ld, ", &ul_holder) != EOF)
	{
		ch_holder |= ul_holder;
		

		// add letters to the buffer in the correct order
		while (n < (char_per_ul - 1))
		{
			buffer[reverse_count] = ch_holder;
			ul_holder = ul_holder >> 8;
			ch_holder = ul_holder;
			n++;
			reverse_count--;

		}
		
		if ((++n) >= char_per_ul)
		{

			buffer[reverse_count] = ch_holder;
			
			// write the buffer to the file
			n = 0;
			while (n < 8)
			{
				fprintf(outfile, "%c", buffer[n]);
				printf("%c", buffer[n]);
				n++;
			}

			// reset variables for next iteration
			n = 0;
			reverse_count = 7;
			ul_holder = 0;
			ch_holder = ul_holder;
		}	
	}

	return 0;
}
