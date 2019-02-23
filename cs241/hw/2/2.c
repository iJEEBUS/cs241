/**
 *  A "pass-by-value" program where an array and its length are 
 *  passed to a function. A new array is created and each item of 
 *  the original array + 10 are inserted into this array. The new 
 *  array is then returned to the user.
 *
 *  Printing functions are only for comparing arrays.
 *
 *  @author Ron Rounsifer
 *  @version 0.02 
 */
#include <stdio.h>
#include <stdlib.h>
#define FOO 5
int * arr_add_10(int arr[], int len);

int main()
{
	int a[FOO] = {1,2,3,4,5};
	int *b; 
	b = arr_add_10(a, FOO);
	
	// print out elements to test

	printf("\na: ");
	for (int j = 0; j < FOO; ++j)
		printf("%d ", a[j]);
	
	printf("\nb: ");
	for (int i = 0; i < FOO; ++i)
		printf("%d ", b[i]);
	printf("\n");	
	
	free(b);
	return 0;
}


int * arr_add_10(int arr[], int len)
{
	// copy the arr
	int *new_arr = malloc(sizeof(int) * len); 
	
	// add 10 to each element
	for (int i = 0; i < len; ++i)
		new_arr[i] += arr[i] + 10;

	return new_arr;
}

