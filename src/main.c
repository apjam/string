#include <stdio.h>

int main() {
  int a = 2, x[1];
  a = 1;
  for (int i = 0; i < a + 10; i++)
    printf("%d\n", x[i]);

  return 0;
}