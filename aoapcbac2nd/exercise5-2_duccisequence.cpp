#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 20

int a[MAXN];
int N;

void input()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", a+i);
  }
}

void solve()
{
  int limit = 10;

  int zero;
  while (limit) {
    zero = 1;
    for (int i = 0; i < N; i++) {
      if (a[i] != 0) zero = 0;
    }
    if (zero) break;

    int a0 = a[0];
    for (int i = 0; i < N; i++) {
      if (i < N - 1) a[i] = abs(a[i] - a[i+1]);
      else a[i] = abs(a[i] - a0);
    }

    limit--;
  }

  if (zero) printf("ZERO\n");
  else printf("LOOP\n");
}

int main()
{
  int rnd;
  scanf("%d", &rnd);
  for (int i = 0; i < rnd; i++) {
    input();
    solve();
  }
}
