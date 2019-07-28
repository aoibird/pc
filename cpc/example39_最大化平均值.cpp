#include <iostream>
#include <algorithm>
#define INF 1000005
#define MAXN 10005
using namespace std;

int w[MAXN];
int v[MAXN];
double vxw[MAXN];
int n, k;

void input()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
}

bool cond(double x)
{
  for (int i = 0; i < n; i++) {
    vxw[i] = v[i] - x * w[i];
  }
  sort(vxw, vxw+n);

  double sum = 0;
  for (int i = n-k; i < n; i++) {
    sum += vxw[i];
  }

  return (sum >= 0);
}

void solve()
{
  double lb = 0, ub = INF; // 单位重量价值的范围，需要得到最大值
  int limit = 100;
  while (limit) {
    double mid = (ub+lb)/2;
    if (cond(mid)) lb = mid;
    else ub = mid;

    limit--;
  }

  printf("%.2f\n", lb);
}

int main()
{
  input();
  solve();
}
