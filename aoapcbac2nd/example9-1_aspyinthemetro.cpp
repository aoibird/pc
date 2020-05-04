#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000;
const int MAXN = 50+10;
const int MAXM = 50+10;
const int MAXT = 200+10;
int times[MAXN], start0[MAXM], start1[MAXM];
int N, T, m1, m2;
int dp[MAXT][MAXN];
bool has_train[MAXT][MAXN][2];

void input()
{
    memset(dp, 0, sizeof(dp));
    memset(has_train, false, sizeof(has_train));
    scanf("%d", &T);
    for (int i = 1; i <= N-1; i++) scanf("%d", &times[i]);
    scanf("%d", &m1);
    for (int i = 0; i < m1; i++) scanf("%d", &start0[i]);
    scanf("%d", &m2);
    for (int i = 0; i < m2; i++) scanf("%d", &start1[i]);
}

void print()
{
    printf("%d %d %d %d\n", N, T, m1, m2);
    for (int i = 0; i < m1; i++) printf("%d ", start0[i]); printf("\n");
    for (int i = 0; i < m2; i++) printf("%d ", start1[i]); printf("\n");
}

void solve()
{
    for (int i = 0; i < m1; i++) {
        int time = start0[i];
        // printf("start time %d ", start0[i]);
        has_train[time][1][0] = true;
        for (int j = 2; j <= N; j++) {
            time += times[j-1];
            has_train[time][j][0] = true;
            // printf("%d ", time);
        }
        // printf("\n");
    }
    for (int i = 0; i < m2; i++) {
        int time = start1[i];
        // printf("start time %d ", start1[i]);
        has_train[time][N][1] = true;
        for (int j = N-1; j >= 1; j--) {
            time += times[j];
            has_train[time][j][1] = true;
            // printf("%d ", time);
        }
        // printf("\n");
    }

    for (int i = 0; i <= N-1; i++) dp[T][i] = INF;
    dp[T][N] = 0;
    for (int i = T-1; i >= 0; i--) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i+1][j] + 1;
            if (j < N && has_train[i][j][0] && i+times[j] <= T)
                dp[i][j] = min(dp[i][j], dp[i+times[j]][j+1]);
            if (j > 1 && has_train[i][j][1] && i+times[j-1] <= T)
                dp[i][j] = min(dp[i][j], dp[i+times[j-1]][j-1]);
        }
    }

}

int main()
{
    int tc = 1;
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        input();
        // print();
        solve();
        printf("Case Number %d: ", tc);
        if (dp[0][1] >= INF) printf("impossible\n");
        else printf("%d\n", dp[0][1]);
        tc++;
    }
}
