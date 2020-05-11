// UVa 10285
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int MAXRC = 100+10;
char name[MAXN];
int field[MAXRC][MAXRC];
int dp[MAXRC][MAXRC];
int R, C;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void input()
{
    scanf("%s%d%d", name, &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) scanf("%d", &field[i][j]);
        getchar();
    }
    memset(dp, -1, sizeof(dp));
}

void print_table()
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int dfs(int r, int c)
{
    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = 0;
    for (int i = 0; i < 4; i++) {
        int tr = r + dr[i], tc = c + dc[i];
        if (field[tr][tc] < field[r][c])
            dp[r][c] = max(dp[r][c], dfs(tr, tc) + 1);
    }
    return dp[r][c];
}

void solve()
{
    int m = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            m = max(m, dfs(i, j));
        }
    }
    // print_table();
    printf("%s: %d\n", name, m);
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        input();
        solve();
    }
}
