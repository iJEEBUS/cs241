#include <stdio.h>
#include <math.h>

int calculate_fourth_roots(int num[], int results[]);


int main()
{

  int nums[20] = {1, 16, 81, 256, 625,
	 	 1296, 2401, 4096, 6561, 
		 10000, 14641, 20736, 28561, 38416,
 		 50625, 65536, 83521, 104976, 130321, 16000 };

  int fourth_roots[20];
  calculate_fourth_roots(nums, fourth_roots);
  return 0;
}

int calculate_fourth_roots(int num[], int results[])
{
  int fourth_root;
  int num_size = sizeof(num)/sizeof(int);
  int n = 4;
    // for each element in the array
  for(int i = 0; i < num_size; i++) 
  {
    fourth_root = num[i];
    // calculate the fourth root
    // add to final array
    for (int j = 0; j < n; j++)
    {
      fourth_root = sqrt(fourth_root);
    }
    results[i] = fourth_root;
  }
  
  return 0;
}
