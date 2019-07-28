#include <iostream>
#include <algorithm>
#define MAXN 100005
using namespace std;

int a[MAXN];
int n, sum;

void input()
{
  scanf("%d%d", &n, &sum);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
}

void solve()
{
  int s = 0, t = 0, mins = n+1, sumc = 0;
  while (1) {
    while (t < n && sumc < sum) sumc += a[t++];
    if (sumc < sum) break;

    mins = min(mins, t-s);
    sumc -= a[s++];
  }

  if (mins > n) mins = 0;
  printf("%d\n", mins);
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
