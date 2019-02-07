#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
/*************************************************************************************
 * A script that calculates the total amount of CPU time that is used in order to 
 * invoke the pow() and sqrt() methods from the time.h library.
 * 
 * Each method is invoked n times (defaults to 100000000) and the CPU times are
 * outputted in milliseconds.
 *
 * @author Ron Rounsifer
 * @version 0.01 - 01.25.2019
 ************************************************************************************/
int main()
{
	/* number of iterations */
	int n = 100000000;
	/* answer to the pow() request */
	double temp_ans = 0.0;
	/* total cpu time used */
	double cpu_time_used;
	/* time at beginning and end of executions */
	clock_t start, end;


	/* clean up the screen for the results of this program */
	system("clear");
	/* Tell user the program is running. Please wait. */
	printf("Program is running ... \n\n");
	
	
	/* timing the power execution */
	start = clock();
	for (int i = 0; i < n; i++) {
		temp_ans = pow(1000.5,222.2);
	}
	end = clock();
	cpu_time_used = (((double) end - start) / CLOCKS_PER_SEC) * 1000;
	printf("CPU time to invoke pow() %d times in milliseconds: %5f\n", n, cpu_time_used);

	/* timing sqrt execution */
	start = clock();
	double b = 0.0;
	for (int i = 0; i < n; i++){
		b = sqrt(temp_ans);
	}
	end = clock();
	cpu_time_used = (((double) end - start) / CLOCKS_PER_SEC) * 1000;
	printf("CPU time to invoke sqrt() %d times in milliseconds: %5f\n", n, cpu_time_used);

	return 0;
}
