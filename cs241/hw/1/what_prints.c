#include <stdio.h>

int main(){
  extern int a, b, c;
  printf("%3d%3d%3d\n",a,b,c);
  return 0;
}

int a, b, c;
