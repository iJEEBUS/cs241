#include <stdio.h>
#include <stdlib.h>

int sum(int);

int main(){
  int total;
  total = sum(4);
  printf("Sum: %d", total);
  return 0;
}

int sum(int n)
{
  int i, total;

  for (i = 0; i < n; i++)
  {
    total += i;
  }
  return total;
}
