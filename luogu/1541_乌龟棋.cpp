// P1541 乌龟棋
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

const int MAXC = 40+2;
const int MAXN = 350+10;
const int CARDS = 4 + 1;
int A[MAXN];
int C[CARDS];
int dp[MAXC][MAXC][MAXC][MAXC];
int N, M;

void print_2darray(int a[MAXN][CARDS], int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) printf("%d%c", a[i][j], j==c-1?'\n':' ');
}


int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
        memset(C, 0, sizeof(C));
        for (int i = 0; i < M; i++) {
            int card; scanf("%d", &card);
            C[card]++;
        }

        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = A[1];
        for (int a = 0; a <= C[1]; a++) {
            for (int b = 0; b <= C[2]; b++) {
                for (int c = 0; c <= C[3]; c++) {
                    for (int d = 0; d <= C[4]; d++) {
                        int t = 1 + a + b*2 + c*3 + d*4;
                        if (a != 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a-1][b][c][d] + A[t]);
                        if (b != 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b-1][c][d] + A[t]);
                        if (c != 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c-1][d] + A[t]);
                        if (d != 0) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d-1] + A[t]);
                    }
                }
            }
        }
        printf("%d\n", dp[C[1]][C[2]][C[3]][C[4]]);
    }
}
