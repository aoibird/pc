// Luogu 1005 矩阵取数游戏
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

const int MAXN = 30+5;
const int MAXM = 50+5;
int matrix[MAXN][MAXM];
int N, M;
ll dp[MAXM][MAXM];

ll solve(int x)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < M; i++) dp[i][i] = matrix[x][i];
    for (int i = M-2; i >= 0; i--) {
        for (int j = i+1; j < M; j++) {
            dp[i][j] = max(matrix[x][i] + dp[i+1][j] * 2, matrix[x][j] + dp[i][j-1] * 2);
        }
    }
    return dp[0][M-1] * 2;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) scanf("%d", &matrix[i][j]);
    }

    ll sum = 0;
    for (int i = 0; i < N; i++) sum += solve(i);
    printf("%lld\n", sum);
}
