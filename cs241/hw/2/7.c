/***********************************************************************
 * An implementation of the strcmp() function that is included in the 
 * string.h header file.
 *
 * Given two strings, sums up their ASCII values, calculates the
 * length of the strings, before comparing the ASCII sums and lengths.
 *
 * Returns:
 *  	  0 if the strings are the same
 * 	  1 if str1 > str2
 * 	 -1 if str1 < str2
 *
 * @author Ron Rounsifer
 * @version 0.01
 ***********************************************************************/

#include <stdio.h>

int str_cmp(char *str1, char *str2);

int main()
{
	char *s1 = "stringer";
	char *s2 = "STRINGER";
	int compare;

	compare = str_cmp(s1, s2);
	printf("%d\n", compare);
	return 0;
}


/***********************************************************************
 * Compares two strings by summing their ASCII values before
 * comparing both those sums and the strings lengths.
 ***********************************************************************/
int str_cmp(char *str1, char *str2)
{
	int str1_sum = 0;
	int str2_sum = 0;
	int str1_len = 0;
	int str2_len = 0;

	// sum up ASCII values of chars	
	for (char *p1 = str1; *p1; ++p1) {
		str1_sum += *p1;
		str1_len++;	
	}
	for (char *p2 = str2; *p2; ++p2) {
		str2_sum += *p2;
		str2_len++;
	}

	// compare ASCII totals and lengths
	if (str1_len > str2_len)
		return 1;
	else if(str1_len < str2_len)
		return -1;
	else if (str1_len == str2_len)
	{
		if (str1_sum > str2_sum)
			return 1;
		else if (str1_sum < str2_sum)
			return -1;
	}	
	return 0;
}
