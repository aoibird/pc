// Luogu 1077 摆花
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MOD = 1000007;
const int MAXN = 100+5;
const int MAXM = 100+5;
int C[MAXN];
int N, M;
int dp[MAXN][MAXM];

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < N; i++) scanf("%d", &C[i]);

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= N; i++) dp[i][0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= M; j++) {
                if (j-1-C[i] >= 0)
                    dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-C[i]] + MOD) % MOD;
                else
                    dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % MOD;
            }
        }
        printf("%d\n", dp[N][M]);
    }
}
