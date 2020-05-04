#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 30+10;
int A[MAXN][3];
int N;
int dp[MAXN][3];
int ans;

void get_abh(int i, int j, int &a, int &b, int &h)
{
    h = A[i][j];
    if (j == 0) a = A[i][1], b = A[i][2];
    else if (j == 1) a = A[i][0], b = A[i][2];
    else if (j == 2) a = A[i][0], b = A[i][1];
    else ;
}

void solve()
{
    ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int a, b, h; get_abh(i, j, a, b, h);
            dp[i][j] = h;
            ans = max(ans, dp[i][j]);
        }
    }

    while (true) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < N; k++) {
                    for (int l = 0; l < 3; l++) {
                        int a, b, h;
                        get_abh(i, j, a, b, h);

                        int c, d, dh;
                        get_abh(k, l, c, d, dh);

                        if (((a > c && b > d) || (a > d && b > c))
                            && dp[i][j] + dh > dp[k][l])  {
                            // printf("%d %d %d %d\n", a, b, c, d);
                            cnt++;
                            dp[k][l] = max(dp[i][j] + dh, dp[k][l]);
                            ans = max(ans, dp[k][l]);
                        }
                    }
                }
            }
        }
        // printf("cnt = %d\n", cnt);
        if (cnt == 0) break;
    }
}

int main()
{
    int tc = 1;
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        memset(dp, 0, sizeof(dp));
        // printf("N = %d ------------------------\n", N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 3; j++)
                scanf("%d", &A[i][j]);
        solve();
        printf("Case %d: maximum height = %d\n", tc, ans);
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < 3; j++) printf("%d ", dp[i][j]);
        //     printf("\n");
        // }

        tc++;
    }
}
