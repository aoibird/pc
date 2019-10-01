// POJ 2229
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000;
int DP[MAXN];
int N;

void print()
{
  for (int i = 0; i <= N; i++) {
    printf("%3d ", DP[i]);
  }
  printf("\n");
}

int main()
{
  scanf("%d", &N);
  fill(DP, DP+N+1, 1);

  for (int k = 1; (1 << k) <= N; k++) {
    for (int s = 1<<k; s <= N; s++) {
      DP[s] = DP[s] + DP[s-(1<<k)];
      DP[s] = DP[s] % 1000000000;
    }
  }
  printf("%d\n", DP[N]);
}
