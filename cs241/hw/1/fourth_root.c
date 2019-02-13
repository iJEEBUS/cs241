/*****************************************************************************
 * A program that calculates the fourth roots of a number.
 * 
 * This example holds a hard-coded list of integers that are fed through
 * the fourth root function individually.
 *
 * @author Ron Rounsifer
 * @version 0.01
 *****************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double calculate_fourth_root(int k);

/*****************************************************************************
 * Entry point of the program.
 *****************************************************************************/
int main()
{

  int nums[] = {1, 16, 81, 256, 625, 
	  	  1296, 2401, 4096, 6561, 10000,
		  14641, 20736, 28561, 38416, 50625,
		  65536, 83521, 104976, 130321, 160000};
  
    printf("Numbers 4th Root\n");
  
  for (int i = 0; i < 20; ++i)
  {
   double fourth_root = calculate_fourth_root(nums[i]);
   printf("%7d %8d\n", nums[i], (int) fourth_root); 
  }
  return 0;
}


/*****************************************************************************
 * Function that actually calculates the fourth root of an integer that is 
 * passed as an argument.
 *
 * @returns double - the fourth root
 * @params int - the number of which to calculate the fourth root of
 *****************************************************************************/
double calculate_fourth_root(int k)
{
  double fourth_root = (double) k;
  int n = 2;
  for (int i = 0; i < n; i++)
  {
    fourth_root = (double) sqrt(fourth_root);
  }
  return fourth_root;
}
