#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 2000+10;
const int MAXK = 2000+10;
const int mod = 1000000007;
int N, K;
int dp[MAXK][MAXN];
vector<int> f[MAXN];

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

void factor(int x)
{
    int i;
    for (i = 1; i*i < x; i++) {
        if (x % i == 0) { f[x].push_back(i); f[x].push_back(x / i); }
    }
    if (i*i == x) f[x].push_back(i);
    sort(f[x].begin(), f[x].end());
}

void solve()
{
    for (int i = 1; i <= N; i++) dp[1][i] = 1;
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < f[j].size(); k++) {
                dp[i][j] = dp[i][j] + dp[i-1][f[j][k]];
                if (dp[i][j] >= mod) dp[i][j] -= mod;
            }
        }
    }
    // print_table();

    int sum = 0;
    for (int j = 0; j <= N; j++) {
        sum = sum + dp[K][j];
        if (sum >= mod) sum -= mod;
    }
    printf("%d\n", sum);
}

int main()
{
    for (int i = 1; i <= MAXN; i++) factor(i);
    while (scanf("%d%d", &N, &K) == 2) {
        memset(dp, 0, sizeof(dp));

        solve();
    }
}
