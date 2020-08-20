// UVa 12563
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50 + 10;
const int MAXT = 180 * MAXN + 678;
int A[MAXN];
int N, T;
int dp[MAXT];
int w[MAXT];


void input()
{
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
}

void solve()
{
    for (int i = 0; i < N; i++) {
        for (int j = T-1; j >= A[i]; j--) {
            if (dp[j]<dp[j-A[i]]+1 || (dp[j]==dp[j-A[i]]+1 && w[j]<w[j-A[i]]+A[i])) {
                dp[j] = dp[j-A[i]] + 1;
                w[j] = w[j-A[i]] + A[i];
            }
        }
    }
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 1; i <= TC; i++) {
        memset(dp, 0, sizeof(dp));
        memset(w, 0, sizeof(w));
        input();
        solve();

        printf("Case %d: %d %d\n", i, dp[T-1]+1, w[T-1]+678);
    }
}
