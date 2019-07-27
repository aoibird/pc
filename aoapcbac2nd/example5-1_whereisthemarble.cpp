#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10005;

int a[maxn];
int n, q;


void solve()
{
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a+n);

  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    int p = lower_bound(a, a+n, x) - a;
    if (a[p] == x) printf("%d found at %d\n", x, p+1);
    else printf("%d not found\n", x);
  }
}

int main()
{
  int cas = 1;
  while (scanf("%d%d", &n, &q) == 2 && n && q) {
    printf("CASE# %d:\n", cas);
    solve();
    cas++;
  }

}
