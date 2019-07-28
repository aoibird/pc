#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  double amount = 95 * n;
  if (amount >= 300) {
    amount = amount * 0.85;
  }
  printf("%.2f\n", amount);
}
