#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 4 // attempted with 5 as well

char* strnsub (char *p, int n);

int main()
{
    char line[] = "His textbook was bought from that bookstore";  
    char *p1, *p2;

   // length of the string
   int size = sizeof(line)/sizeof(line[0]);

    // set p1 to the beginning of string line;
    p1 = line;
    
    while ( *p1 !=  line[size]) 	
    {
        // set p2 to the position immediately after p1
        p2 = p1 + sizeof(char);
		
        while ( *p2 != line[size] )	
        {
            if (strncmp(p1, p2, LEN) == 0) // use strncmp() to compare
            {
                printf("The original string is:\n%s\n", line);
                printf("The first substring:  %s\n", strnsub(p1, LEN));
                printf("The second substring: %s\n", strnsub(p2, LEN));
                return 0;
            }
				
           // advance p2 to the next position
	   p2 = p2 + sizeof(char);
        }

        // advance p1 to the next position
	p1 = p1 +sizeof(char);
    }
    printf("No repeated patterns of length %d in the following string:\n%s\n",
            LEN, line);
    return 0;
}


// returns a string with the first n characters of string p
char* strnsub (char *p, int n)
{
    char match[n+1];
    for (int i = 0; i < n; ++i)
    {
        match[i] = p[i];
    }
    match[n] = '\0';
    p = match;
    return p; 
}
