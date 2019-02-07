/* main function for lab1 */
#include "lab1.h"
/** 
 * Lab 01.
 * Implementation of a coin toss in c.
 * Executes for 16 iterations.
 * Outputs percentage of difference of heads/tails.
 * 
 * @author Ron Rounsifer
 * @version 0.01 - 01.23.2019
 */
int main()
{
	printf("\nRAND_MAX = %d\n", RAND_MAX);

	random_char(200000);
	
	int num = 100;
	int num_iterations = 16;
	double delta = 0;
	printf("%20s\t%-20s\n", "Runs", "Difference");
	
	// Run the coin_tos game 16 times. 
	// Multiply num by 3 each iteration
	// Calculate percentage of difference and print
	for (int i = 0; i < num_iterations; i++) 
	{
		delta = coin_toss(num);	
		printf("%20d\t%-20f\n", num, delta/num);
		num = num * 3;
	}
	return 0;
}
