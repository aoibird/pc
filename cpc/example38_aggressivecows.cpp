#include <iostream>
#include <algorithm>
#define MAXN 100005
#define INF 1000000005
using namespace std;

int a[MAXN];
int n, m;

void input()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}

bool cond(int d)
{
  int last = 0;
  int curr;
  for (int i = 1; i < m; i++) {
    curr = last+1;
    while (curr < n && a[curr] - a[last] < d) curr++;
    if (curr == n) return false;

    last = curr;
  }

  return true;
}

void solve()
{
  sort(a, a+n);

  int lb = 0, ub = INF;
  int mid;
  while (ub - lb > 1) {
    mid = (lb+ub)/2;
    if (cond(mid)) lb = mid;
    else ub = mid;

  }

  printf("%d\n", lb);
}

int main()
{
  input();
  solve();
}
