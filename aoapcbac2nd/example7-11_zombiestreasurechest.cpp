#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[(1 << 20)];
int N, S1, V1, S2, V2;

int main()
{
  int T;
  scanf("%d", &T);
  for (int k = 0; k < T; k++) {
    scanf("%d%d%d%d%d", &N, &S1, &V1, &S2, &V2);

    //memset(dp, 0, sizeof(dp)); // too slow
    for (int i = 0; i <= N; i++) dp[i] = 0;

    for (int i = 0; i < 2; i++) {
      int s, v;
      if (i == 0) { s = S1; v = V1; }
      else { s = S2; v = V2; }
      for (int j = s; j <= N; j++) {
        dp[j] = max(dp[j-s] + v, dp[j]);
      }
    }

    printf("Case #%d: %d\n", k+1, dp[N]);
  }

}
