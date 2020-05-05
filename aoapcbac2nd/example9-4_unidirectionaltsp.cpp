// UVa 116
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXR = 10+10;
const int MAXC = 100+10;
const int INF = 1 << 30;
int F[MAXR][MAXC];
int dp[MAXR][MAXC];
int nxt[MAXR][MAXC];
int R, C;

void print_table()
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) printf("%d(%d) ", dp[i][j], nxt[i][j]);
        printf("\n");
    }
    printf("\n");
}

void solve()
{
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) dp[r][c] = INF;
    for (int r = 0; r < R; r++) dp[r][C-1] = F[r][C-1];

    for (int c = C-2; c >= 0; c--) {
        for (int r = 0; r < R; r++) {
            int up = (r-1+R)%R;
            int down = (r+1)%R;
            if (dp[r][c] > dp[up][c+1] + F[r][c]
                || (dp[r][c] == dp[up][c+1] + F[r][c] && nxt[r][c] > up)) {
                dp[r][c] = dp[up][c+1] + F[r][c];
                nxt[r][c] = up;
            }
            if (dp[r][c] > dp[r][c+1] + F[r][c]
                || (dp[r][c] == dp[r][c+1] + F[r][c] && nxt[r][c] > r)) {
                dp[r][c] = dp[r][c+1] + F[r][c];
                nxt[r][c] = r;
            }
            if (dp[r][c] > dp[down][c+1] + F[r][c]
                || (dp[r][c] == dp[down][c+1] + F[r][c] && nxt[r][c] > down)) {
                dp[r][c] = dp[down][c+1] + F[r][c];
                nxt[r][c] = down;
            }
        }
    }
    // print_table();

    int row, ans = INF;
    for (int r = 0; r < R; r++)
        if (dp[r][0] < ans) { ans = dp[r][0]; row = r; }
    printf("%d", row+1);
    for (int i = 0; i < C-1; i++) {
        printf(" %d", nxt[row][i]+1);
        row = nxt[row][i];
    }
    printf("\n%d\n", ans);
}

int main()
{
    while (scanf("%d%d", &R, &C) == 2) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) scanf("%d", &F[i][j]);
        // printf("INF = %d\n", INF);
        solve();
    }
}
