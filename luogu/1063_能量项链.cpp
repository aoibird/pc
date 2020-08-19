// Luogu 1063 能量项链
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

const int MAXN = 1000+5;
int A[MAXN];
int N;
int dp[MAXN][MAXN];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    memset(dp, 0, sizeof(dp));
    int maxv = 0;
    for (int l = 2; l <= N; l++) {
        for (int i = 0; i < N; i++) {
            int j = (i+l-1)%N, j1 = (i+l)%N;
            for (int t = 1; t < l; t++) {
                int k = (i+t-1)%N, k1 = (i+t)%N;
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k1][j] + A[i] * A[k1] * A[j1]);
                if (l == N) maxv = max(maxv, dp[i][j]);
            }
        }
    }
    printf("%d\n", maxv);
}
