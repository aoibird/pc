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

const int MOD = 1e6 + 7;
const int MAXN = 100+5;
const int MAXM = 100+5;
int C[MAXN];
int N, M;
int dp[MAXM];

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < N; i++) scanf("%d", &C[i]);

        memset(dp, 0, sizeof(dp));
        for (int j = 0; j <= C[0]; j++) dp[j] = 1;
        for (int i = 1; i < N; i++) {
            int sum = 0;
            for (int j = M; j > M-C[i] && j >= 0; j--) sum = (sum+dp[j]) % MOD;
            for (int j = M; j >= 0; j--) {
                sum = (sum-dp[j]+MOD) % MOD;
                if (j-C[i] >= 0) sum = (sum+dp[j-C[i]]) % MOD;
                dp[j] = (dp[j]+sum) % MOD;
            }
            // for (int j = 0; j <= M; j++) printf("%d%c", dp[j], j==M?'\n':' ');
        }
        printf("%d\n", dp[M]);
    }
}
