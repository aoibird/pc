// Luogu 1220 关路灯
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

const int INF = 1e9;
const int MAXN = 50+5;
int L[MAXN];
int W[MAXN];
int S[MAXN];
int N, C;
int dp[MAXN][MAXN][2];

int cost(int f, int t, int dist)
{
    int all = S[N], closed = S[t] - S[f-1];
    return dist * (all - closed);
}

int main()
{
    while (scanf("%d%d", &N, &C) == 2) {
        for (int i = 1; i <= N; i++) scanf("%d%d", &L[i], &W[i]);
        S[1] = W[1];
        for (int i = 2; i <= N; i++) S[i] = S[i-1] + W[i];

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++) dp[i][j][0] = dp[i][j][1] = INF;

        dp[C][C][0] = dp[C][C][1] = 0;
        for (int j = C; j <= N; j++) {
            for (int i = j-1; i >= 1; i--) {
                dp[i][j][0] = min(dp[i+1][j][0] + cost(i+1, j, L[i+1]-L[i]),
                                  dp[i+1][j][1] + cost(i+1, j, L[j]-L[i]));
                dp[i][j][1] = min(dp[i][j-1][0] + cost(i, j-1, L[j]-L[i]),
                                  dp[i][j-1][1] + cost(i, j-1, L[j]-L[j-1]));
            }
        }
        printf("%d\n", min(dp[1][N][0], dp[1][N][1]));
    }
}
