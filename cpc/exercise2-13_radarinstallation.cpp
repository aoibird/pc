#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1010
using namespace std;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
PII PS[MAXN];
PDD R[MAXN];
int N, D;

const double ERR = 1e-7;

void print()
{
  for (int i = 0; i < N; i++) {
    printf("%d %d %.6f %.6f\n", PS[i].first, PS[i].second, R[i].first, R[i].second);
  }
}

void input()
{
  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    PS[i] = PII(x, y);
  }
}

bool compare(const PDD &a, const PDD &b)
{
    if (a.second < b.second) return true;
    else if (a.second == b.second) return a.first < b.first;
    else return false;
}

void solve()
{
    for (int i = 0; i < N; i++) {
        int x = PS[i].first, y = PS[i].second;
        if (y > D) { printf("-1\n"); return; }
        double l = sqrtl(D*D - y*y);
        R[i] = PDD(x-l, x+l);
    }

    sort(R, R+N, compare);
    int cnt = 0, index = 0;
    while (index < N) {
        double pos = R[index].second; // right most
        while (R[index].first < pos + ERR) index++;
        cnt++;
    }
    printf("%d\n", cnt);
}

int main()
{
  int TC = 1;
  while(scanf("%d%d", &N, &D) == 2) {
      if (N == 0 && D == 0) break;
      input();
      printf("Case %d: ", TC);
      solve();
      TC++;
  }
}
