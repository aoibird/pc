#include <stdio.h>

int main()
{
  for (int x = 100; x < 1000; x++) {
    int x2 = x / 100;
    int x1 = (x % 100) / 10;
    int x0 = x % 10;
    if (x2*x2*x2 + x1*x1*x1 + x0*x0*x0 == x) {
      printf("%d\n", x);
    }
  }
}
