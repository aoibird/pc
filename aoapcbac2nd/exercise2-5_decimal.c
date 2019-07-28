#include <stdio.h>
#include <math.h>
#define MAX 100

int main()
{
  int a, b, c;
  int i = 1;
  char str[MAX];
  while (scanf("%d%d%d", &a, &b, &c) == 3 &&
         a != 0 && b != 0 && c != 0) {
    sprintf(str, "Case %%d: %%.%df\n", c);
    printf(str, i, a / (double) b);

    i++;
  }
}
