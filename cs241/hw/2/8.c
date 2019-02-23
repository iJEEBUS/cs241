#include <stdio.h>

int main()
{
	char *p[2][3] = {{"abc", "defg", "hi"}, {"jklmno", "pqrstuvw", "xyz"}};

	printf("1: %c\n", ***p);
	printf("2: %c\n", **p[1]);
	printf("3: %c\n", **(p[1]+2));
	printf("4: %c\n", *(*(p+1)+1)[7]);
	printf("5: %c\n", (* (* (p+1) + 1 ) )[7] );
	printf("6: %c\n", *(p[1][2] + 2));
	return 0;
}
