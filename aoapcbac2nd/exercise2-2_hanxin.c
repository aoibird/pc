#include <stdio.h>

int solve(int a, int b, int c)
{
  for (int i = 10; i < 100; i++) {
    if (i % 3 == a && i % 5 == b && i % 7 == c) {
      return i;
    }
  }

  return -1;
}

int main()
{
  int a, b, c, i = 1;
  while (scanf("%d%d%d", &a, &b, &c) == 3) {
    int result = solve(a, b, c);
    if (result == -1) {
      printf("Case %d: No answer\n", i);
    }
    else {
      printf("Case %d: %d\n", i, result);
    }

    i++;
  }

}
