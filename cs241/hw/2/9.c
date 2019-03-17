#include <stdio.h>
#include <string.h>
char* q9(char *s);

int main()
{
	char *str = "string";
	char *ans;

	ans = q9(str);
	printf("%s\n", ans);
	return 0;
}

char* q9(char *s)
{
	char *p, *q, tmp;
	if (s == NULL)
		return s;

	int n = strlen(s);

	// p points to front
	// q points to end
	// flips on each pass through
	q = (n > 0) ? s + n - 1 : s;
	for (p = s; p < q; q--, p++)
	{
		tmp = *p;
		
		printf("p: %c\n", *p);
		printf("temp: %c\n", tmp);
		printf("q: %c\n", *q);

		//		*p = *q;
		*q = tmp;
	}

	return s;
}
