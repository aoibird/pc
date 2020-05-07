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
int dp[MAXN][MAXT];
int w[MAXN][MAXT];
int ans;


void input()
{
    scanf("%d%d", &N, &T);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
}

void print_table()
{
    for (int i = 0; i <= N; i++) {
        for (int j = 80; j < T; j++) {
            printf("%d(%d)%c", dp[i][j], w[i][j],j==T-1?'\n':' ');
        }
    }
    printf("\n");
}

void solve()
{
    ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < T; j++) {
            if (j < A[i]) {
                dp[i][j] = dp[i-1][j];
                w[i][j] = w[i-1][j];
            }
            else {
                if (dp[i-1][j] > dp[i-1][j-A[i]] + 1) {
                    dp[i][j] = dp[i-1][j];
                    w[i][j] = w[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j-A[i]]+1;
                    w[i][j] = w[i-1][j-A[i]] + A[i];
                }
            }
        }
    }
    // print_table();
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 1; i <= TC; i++) {
        memset(dp, 0, sizeof(dp));
        memset(w, 0, sizeof(w));
        input();
        solve();

        printf("Case %d: %d %d\n", i, dp[N][T-1]+1, w[N][T-1]+678);
    }
}
