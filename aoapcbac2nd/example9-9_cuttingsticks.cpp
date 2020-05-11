// UVa 10003
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50+10;
const int INF = 100000000;
int A[MAXN];
int N, L;
int dp[MAXN][MAXN];

void print_table()
{
    for (int i = 0; i <= N+1; i++) {
        for (int j = 0; j <= N+1; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solve()
{
    for (int i = 0; i <= N+1; i++)
        for (int j = 0; j <= N+1; j++) dp[i][j] = INF;
    A[0] = 0; A[N+1] = L;
    // print_table();
    for (int i = 0; i <= N; i++) dp[i][i+1] = 0;
    // print_table();
    for (int l = 1; l <= N+1; l++) {
        for (int i = 0; i <= N && i+l <= N+1; i++) {
            for (int k = i+1; k < i+l; k++) {
                // printf("[%d, %d) k = %d ", i, i+l, k);
                // printf("%d + %d + %d\n", dp[i][k], dp[k][i+l],
                //        A[i+l]-A[i]);
                dp[i][i+l] = min(dp[i][k]+dp[k][i+l]+A[i+l]-A[i],dp[i][i+l]);
            }
        }
    }
    // print_table();

    printf("The minimum cutting is %d.\n", dp[0][N+1]);
}

int main()
{
    while (scanf("%d", &L) == 1) {
        if (L == 0) break;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &A[i+1]);
        memset(dp, 0, sizeof(dp));

        solve();
    }
}
