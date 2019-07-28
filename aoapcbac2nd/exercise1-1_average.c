#include <stdio.h>

int main()
{
  int n = 3;
  int a;
  scanf("%d", &a);
  int sum = a;
  for (int i = 1; i < n; i++) {
    scanf("%d", &a);
    sum += a;
  }

  printf("%.3f\n", sum / (double) n);
}
