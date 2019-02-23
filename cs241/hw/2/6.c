#include <stdio.h>

int main()
{
	printf("%c%c%c%c%c!\n", "ghi"[1], *("def"+1), *"def" + 1, "klm"[1], *"ghi" + 8);
	return 0;
}
