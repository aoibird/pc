#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 4000+10;
int DP[MAXN];

int main()
{
  int N, a, b, c;
  scanf("%d%d%d%d", &N, &a, &b, &c);
  DP[a] = DP[b] = DP[c] = 1;
  int s = max(a, max(b, c));
  for (int i = s; i <= N; i++) {
    DP[i] = max(DP[i-a], max(DP[i-b], DP[i-c])) + 1;
  }
  // for (int i = 0; i <= N; i++) printf("%d%c", DP[i],i==N?'\n':' ');
  printf("%d\n", DP[N]);
}
