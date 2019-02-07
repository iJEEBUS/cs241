#include <stdio.h>
#include <stdlib.h>
/****************************************************************
 * Bubble Sort and Selection Sort algorithm implmentations in C.
 *
 * @author Ron Rounsifer
 * @version 0.01 (01.22.2019 - OG)
 ***************************************************************/

/****************************************************************
 * Bubble Sort
 ***************************************************************/
int bubble_sort(int *arr, int n)
{
  if (n == 1) 
  {
    return 0;
  }
  // iterate until sorted
  for (int i = 0; i < n; i++)
  {
    // For each element in the array
    for (int j = 0; j < n-1; j++)
    {
      // Compare neighborings elements, swap if needed
      if (arr[j] > arr[j+1])
        {
          int temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
        }
      }
    }
  return 0;
}


/****************************************************************
 * Selection Sort
 ***************************************************************/
int selection_sort(int *arr, int n)
{
  if (n == 1) 
  {
    return 0;
  }

  int min = -1;
  int min_index = -1; 

  // for each element 
  for (int i = 0; i < n; i++) 
  {
    min = arr[i];
    // check for the minimun in the rest of the array
    // always set min if first iteration
    for (int j = i+1; j < n; j++)
    {
      if (arr[j] < min)
      {
	min = arr[j];
        min_index = j;
      }
    }

    if (min < arr[i])
    {
      arr[i] = min;
    }  
  }
  return 0;
}
