#include <stdio.h>
#define FOO 5
int[] arr_add_10(int arr[], int len);

int main()
{
	int a[FOO] = {1,2,3,4,5};
	int b[FOO] = arr_add_10(a, FOO);
	
	// print out elements to test
	for (int i = 0; i < FOO; ++i)
	{
		printf("%d\n");
	}
	return 0;
}


int[] arr_add_10(int arr[], int len)
{
	// copy the arr
	int[] new_arr = arr[];
	
	// add 10 to each element
	for (int i = 0; i < len; ++i)
		new_arr[i] += 10;

	return new_arr;
}

