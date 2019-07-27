#include <stdio.h>
#include <string.h>
#define MAXS 85

void solve()
{
  char str[MAXS];
  scanf("%s", str);
  int len = strlen(str);
  int p;
  for (p = 1; p < len; p++) {
    if (len % p != 0) continue;
    int ok = 1;
    for (int j = 0; j < p && ok; j++) {
      int x = str[j];
      for (int i = j; i < len && ok; i+= p) {
        if (str[i] != x) ok = 0;
      }
    }

    if (ok == 1) break;
  }

  printf("%d\n", p);
}

int main()
{
  int rnd;
  scanf("%d", &rnd); getchar();
  for (int i = 0; i < rnd; i++) {
    if (i != 0) printf("\n");
    solve();
  }
}
