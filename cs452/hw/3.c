#include <stdio.h>
#include <unistd.h>

int main() {
  int i;
  int num_forks = 1;

  for (i = 0; i < 4; i++) {
    fork();
    num_forks += 1;
    printf("Forks: %d\n ", (num_forks));
  }
  return 0;
}
