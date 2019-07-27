*/
#include <stdio.h>
#include <string.h>
#define MAXS 10

void solve()
{
  int n;
  scanf("%d", &n);
  char str[MAXS];
  int digit[10];
  memset(digit, 0, sizeof(digit));
  memset(str, 0, sizeof(str));
  for (int i = 1; i <= n; i++) {
    sprintf(str, "%d", i);
    //printf("%s", str);
    char *p = str;
    while (*p != '\0') {
      digit[*p - '0'] += 1;
      p++;
    }
  }

  printf("%d", digit[0]);
  for (int i = 1; i < 10; i++) {
    printf(" %d", digit[i]);
  }
  printf("\n");
}

int main()
{
  int rnd;
  scanf("%d", &rnd);
  for (int i = 0; i < rnd; i++) {
    solve();
  }
}
