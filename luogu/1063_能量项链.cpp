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

const int MAXN = 100+5;
int A[MAXN];
int N;
int dp[MAXN][MAXN];

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        memset(dp, 0, sizeof(dp));
        int maxv = 0;
        for (int l = 2; l <= N; l++) {
            for (int i = 0; i < N; i++) {
                int j = (i+l-1) % N;
                for (int t = 1; t <= l-1; t++) {
                    int k = (i+t-1)%N, k1 = (i+t)%N;
                    // printf("[%d %d %d %d] %d %d %d*%d*%d=%d\n", i, k, k1, j,
                    //        dp[i][k], dp[k1][j], A[i], A[k1], A[(j+1)%N],
                    //        A[i]*A[k1]*A[(j+1)%N]);
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k1][j] + A[i] * A[k1] * A[(j+1)%N]);
                    maxv = max(maxv, dp[i][j]);
                }
            }
        }
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) printf("%d ", dp[i][j]);
        //     printf("\n");
        // }
        printf("%d\n", maxv);
    }
}
