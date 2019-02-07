/************************************************************************
 * Times both the average and worst cases for sorting an array
 * of size n using my implementations of the Bubble Sort and 
 * Selection Sort algorithms.
 *
 * @author Ron Rounsifer
 * @version 0.02 (02.4.2019 - 01.22.2019)
 ***********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./sort.h"

#define SIZE 32

int main()
{
  /* Reference to array size */
  int arr_size;

  /* Seed so we can repeat the same random sequence */
  int seed = time(NULL);
  srand(seed);


  while(1)
  {
    /* get size of array from user */
    printf("Please input the size of the array: ");
    scanf("%d", &arr_size);
    
    /* check for exit */
    if (arr_size < 1) 
    {
      break;
    }

    /* references variables for array and buffer */
    int* arr;
    int* arr2;
    printf("Executing bubble sort");

    /* Allocate enough memory for the arrays */
    arr = malloc(sizeof(int)*(arr_size));
    arr2 = malloc(sizeof(int)*(arr_size));

    /* populate random arrays */
    for (int i = 0; i < arr_size; i++) 
    {
      int num = rand();
      arr[i] = num;
      arr2[i] = num;
    }
    
    /* timing variables */
    clock_t begin;
    clock_t end;
    double avg_bubble;
    double best_bubble;
    double avg_selection;
    double best_selection;

    printf("Executing bubble sort");
    

    /************************************************************************
     * Bubble Sort timing.
     *
     * These are used to time avg and best cases for bubble sort.
     * Initially, the random array is sorted (avg case) then this sorted
     * array is passed through again (best case).
     *
     * The memory location of arr is freed after completion.
     ***********************************************************************/

    /* average case */ 
    begin = clock();
    bubble_sort(arr, arr_size);
    end = clock();
    avg_bubble = ((double) (end-begin) / CLOCKS_PER_SEC) * 1000;
    
    /* best case */
    begin = clock();
    bubble_sort(arr, arr_size);
    end = clock();
    best_bubble = ((double) (end-begin) / CLOCKS_PER_SEC) * 1000;
    
    /* free memory */
    free(arr);



    /************************************************************************    
     * Selection Sort timing.
     *
     * Initially, the random array is sorted (avg case) then this sorted
     * array is passed through again (best case).
     *
     * The memory location of arr2 is freed after completion.
     ***********************************************************************/

    /* avg case */
    begin = clock();
    selection_sort(arr2, arr_size); 
    end = clock();
    avg_selection = ((double)(end-begin) / CLOCKS_PER_SEC) * 1000;

    /* best case */ 
    begin = clock();
    selection_sort(arr2, arr_size); 
    end = clock();
    best_selection = ((double)(end-begin) / CLOCKS_PER_SEC) * 1000;
    
    /* free memory */
    free(arr2);



    /************************************************************************ 
     * Handles the printing of the desired output.
     * If the array is of length 50 or less, then all of the numbers
     * are printed. Otherwise, only the timing information is printed.
     ***********************************************************************/
    if (arr_size <= 50) 
    {
      /* bubble sort output */
      printf("Here is the sorted array in an ascending order:");
      
      /* print array */
      for (int i = 0; i < arr_size; i++) 
      {
        if (i % 5 == 0) 
        {
          printf("\n");
        }
        printf("%10d\t", arr[i]);
      }
      printf("\n%10s %10s %10s %10s", "Array_Size", "Algorithm", "Average", "Best");
      printf("\n%10d %10s %10f %10f\n", arr_size, "Bubble", avg_bubble, best_bubble);

     /* selection sort output */
     printf("\nHere is the sorted array in an ascending order:");
      /* print array */
      for (int i = 0; i < arr_size; i++) 
      {
        if (i % 5 == 0) 
        {
          printf("\n");
        }
        printf("%10d\t", arr[i]);
      }
      printf("\n%10s %10s %10s %10s", "Array_Size", "Algorithm", "Average", "Best");
      printf("\n%10d %10s %10f %10f\n", arr_size, "Selection", avg_selection, best_selection); 
    } else {
      printf("%10s %10s %10s %10s\n", "Array_Size", "Algorithm", "Average", "Best");
      printf("%10d %10s %10f %10f\n", arr_size, "Bubble", avg_bubble, best_bubble);
      printf("%10d %10s %10f %10f\n", arr_size, "Selection", avg_selection, best_selection);
    }
  }
    return 0;
}
