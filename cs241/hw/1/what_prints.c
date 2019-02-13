#include <stdio.h>

int main(){
  extern int a, b, c;
  printf("%3d%3d%3d\n",a,b,c);
  return 0;
}

static int a=1, b=3, c=3;
