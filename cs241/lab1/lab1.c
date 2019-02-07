/* implement the functions and start the program */
#include "lab1.h"

/* *******************************************************************************
 * Generates a random sequence of characters n times and compute the frequency of
 * each charaters, then display the results
 * 
 *
 * @author Ron Rounsifer
 * @version 0.01 - 01.23.2019 
 ********************************************************************************/
int random_char(int n)
{
	int freq[26];	/* frequency of each letter (lower case only) */

	int i, j;
	
	for (i = 0; i < 26; i++)
		freq[i] = 0; /* initialize the array */

	/* generate the random sequence n times in a loop */
	for (i = 0; i < n; i++)
	{
		j = rand() % 26;
		freq[j] += 1;
	}

	/* compute the max frequency */
	j = 0;
	for (i = 0; i < 26; i++)
	{
		if (freq[i] > j)
			j = freq[i];
	}

	/* display the results */
	printf("\nHere are the frequencies:\n");
	for (i = 0; i < 26; i++)
	{
		printf("%2c: %4d", 'a' + i, freq[i]);
		if((i + 1) % 5 == 0)
			printf("\n");
	}	
	printf("\n\n");

	printf("Here is the max frequency value:\n");
	for (i = 0; i < 26; i++)
	{
		if (freq[i] >= j)
			printf("%2c: %4d\n", 'a' + i, freq[i]);
	}
	printf("\n");

	return 0;
}

/*******************************************************************************
 * Toss the coin the coin n times. 
 * Heads == even, Tails == odd.
 *
 * @return delta - absolute difference (heads - tails)
 ******************************************************************************/
double coin_toss(int n)
{
	int num_heads = 0;
	int num_tails = 0;
	double delta = 0;

	/* Flip the coin n times */
	for (int i = 0; i < n; i++) {
		int flip = rand();

		/* Heads if even */
		/* Tails if odd */
		if (flip % 2 == 0) {
			num_heads++;
		} else {
			num_tails++;
		}
	}
	
	/* Absoulute difference (heads - tails) */
	delta = abs(num_heads - num_tails);
	return delta;
}
