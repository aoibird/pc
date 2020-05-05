// UVa 1347
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> PII;

const int MAXN = 1000+10;
const int INF = 10000000;
PII P[MAXN];
int N;
double dp[MAXN][MAXN];

double dist(int x, int y)
{
    int a = P[x].first; int b = P[x].second;
    int c = P[y].first; int d = P[y].second;
    return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

void print_table()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] < INF) printf("%.2lf ", dp[i][j]);
            else printf("INF ");
        }
        printf("\n");
    }
}

void solve()
{
    double ans = INF;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = INF;
    dp[1][0] = dist(0, 1);
    for (int i = 1; i < N-1; i++) {
        for (int j = 0; j < i; j++) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dist(i, i+1));
            dp[i+1][i] = min(dp[i+1][i], dp[i][j] + dist(j, i+1));
        }
    }
    // print_table();
    // for (int j = 0; j < N-1; j++)
    //     printf("%.2lf(%.2lf + %.2lf (%d, %d)) ", dp[N-1][j]+dist(j, N-1),
    //            dp[N-1][j], dist(j, N-1), N-1, j);
    // printf("\n");
    for (int j = 0; j < N-1; j++)
        ans = min(ans, dp[N-1][j]+dist(j, N-1));
    printf("%.2lf\n", ans);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) {
            int a, b; scanf("%d%d", &a, &b);
            P[i] = PII(a, b);
        }
        solve();
    }
}
