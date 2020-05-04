#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXNMB = 500+10;
int n, m, b, mod; // n,m ~ [1, 500] b ~ [0, 500] mod ~ [1, 10^9+7]
int A[MAXNMB];
int dp[MAXNMB][MAXNMB];

void solve()
{
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = A[i]; k <= b; k++) {
                if (dp[j-1][k-A[i]] != 0) {
                    dp[j][k] = (dp[j][k] + dp[j-1][k-A[i]]) % mod;
                }
            }
        }
    }
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= b; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    int ans = 0;
    for (int i = 0; i <= b; i++) {
        ans = (ans + dp[m][i]) % mod;
    }
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d%d%d%d", &n, &m, &b, &mod) == 4) {
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        memset(dp, 0, sizeof(dp));
        solve();
    }
}
