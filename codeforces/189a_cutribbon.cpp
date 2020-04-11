#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 4000+10;
const int K = 3;
int DP[MAXN];
int N;
int C[K];

int main()
{
  scanf("%d%d%d%d", &N, &C[0], &C[1], &C[2]);
  memset(DP, 0, sizeof(DP));
  for (int i = 0; i < K; i++) DP[C[i]] = 1;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j < K; j++) {
      if (i - C[j] >= 0 && DP[i-C[j]] > 0)
        DP[i] = max(DP[i], DP[i-C[j]] + 1);
    }
  }
  // for (int i = 0; i <= N; i++) printf("%d%c", DP[i],i==N?'\n':' ');
  printf("%d\n", DP[N]);
}
