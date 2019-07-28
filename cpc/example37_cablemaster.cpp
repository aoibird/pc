#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 10005
#define INF 100005
using namespace std;

double a[MAXN];
int n;
int k;

void input()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}

bool cond(double x)
{

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (int)(a[i] / x);
  }
  //printf("%d\n", sum);

  return (sum >= k);
}

void solve()
{
  double lb = 0;
  double ub = INF;
  int limit = 100;
  double mid;
  while (limit) {
    mid = (ub+lb)/2;
    //printf("%lf\n", mid);
    if (cond(mid)) lb = mid;
    else ub = mid;

    limit--;
  }

  printf("%.2f\n", floor(ub*100)/100);
}

int main()
{
  input();
  solve();
}
