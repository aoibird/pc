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

const int MAXN = 2000+10;
const int MAXK = 2000+10;
int N, K;
int dp[MAXK][MAXN];

void print_table()
{
    for (int i = 1; i <= K; i++) {
        printf("%d: ", i);
        for (int j = 1; j <= N; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}

void solve()
{
    for (int i = 1; i <= N; i++) dp[1][i] = 1;
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (j % k == 0) dp[i][j] += dp[i-1][k];
            }
        }
    }
    // print_table();

    int sum = 0;
    for (int j = 0; j <= N; j++) sum += dp[K][j];
    printf("%d\n", sum);
}

int main()
{
    while (scanf("%d%d", &N, &K) == 2) {
        memset(dp, 0, sizeof(dp));

        solve();
    }
}
