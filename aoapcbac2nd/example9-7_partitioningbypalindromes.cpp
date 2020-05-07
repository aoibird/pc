// UVa 11584
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXL = 1000+10;
char S[MAXL];
int L;
int dp[MAXL];
bool palin[MAXL][MAXL];

void print_table()
{
    for (int i = 0; i < L; i++) printf("%d ", dp[i]); printf("\n");
    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++) printf("%d%c", palin[i][j], j==L-1?'\n':' ');
}

void mark_palin(int x)
{
    for (int i = 0; x-i >= 0 && x+i < L; i++) {
        if (S[x+i] != S[x-i]) break;
        palin[x-i][x+i] = true;
    }
    for (int i = x, j = x+1; i >= 0 && j < L; i--, j++) {
        if (S[i] != S[j]) break;
        palin[i][j] = true;
    }
}

void solve()
{
    for (int i = 0; i < L; i++) mark_palin(i);

    for (int i = 0; i < L; i++) {
        dp[i] = i+1;
        // if (palin[0][i]) dp[i] = 1;
        for (int j = 0; j <= i; j++) {
            if (palin[j][i]) dp[i] = min(dp[i], (j==0?0:dp[j-1]) + 1);
        }
    }
    // print_table();
    printf("%d\n", dp[L-1]);
}

int main()
{
    int TC; scanf("%d", &TC); getchar();
    for (int tc = 0; tc < TC; tc++) {
        memset(dp, 0, sizeof(dp));
        memset(palin, 0, sizeof(palin));
        scanf("%s", S); getchar();
        L = strlen(S);
        solve();
    }
}
