// Luogu 4170 涂色
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
const int LETTERS = 26;
char S[MAXN];
int dp[MAXN][MAXN][LETTERS];
int N;

void color(int l, int r, int p, int q)
{
    // printf("coloring: (%d %d) (%d %d)\n", l, r, p, q);
    for (int i = 0; i < LETTERS; i++) {
        for (int j = 0; j < LETTERS; j++) {
            if (dp[l][r][i] < INF && dp[p][q][j] < INF) {
                // printf("    (%d %d) %c %c\n", l, q, j+'A', i+'A');
                dp[l][q][j] = min(dp[l][q][j], dp[l][r][i] + dp[p][q][j] + (i==j?0:1));
                dp[l][q][i] = min(dp[l][q][i], dp[l][r][i] + dp[p][q][j] + (i==j?0:1));
            }
        }
    }
}

void print_dp()
{
    for (int l = 1; l <= N; l++) {
        for (int i = 0, j = i+l-1; j < N; i++, j++) {
            printf("(%d %d)\n", i, j);
            for (int a = 0; a < LETTERS; a++) {
                if (dp[i][j][a] < INF) printf("%d ", dp[i][j][a]);
                else printf("I ");
            }
            printf("\n");
        }
    }
}

int main()
{
    while (scanf("%s", S) == 1) {
        N = strlen(S);
        memset(dp, 0x3f, sizeof(dp));

        for (int i = 0; i < N; i++) dp[i][i][S[i]-'A'] = 0;
        for (int l = 1; l <= N; l++) {
            for (int i = 0, j = i+l-1; j < N; i++, j++) {
                for (int k = i; k < j; k++) {
                    color(i, k, k+1, j);
                }
            }
        }
        // print_dp();
        int m = INF;
        for (int a = 0; a < LETTERS; a++) m = min(m, dp[0][N-1][a]);
        printf("%d\n", m+1);
    }
}
