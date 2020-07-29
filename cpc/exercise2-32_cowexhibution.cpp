// POJ 2184
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

const int MAXN = 100+10;
const int MAXSF = 1000+5;
const int MAXT = 1e5 + 10;
int S[MAXN];
int F[MAXN];
int dp[MAXT*2+10];
int N;

void print_array(bool *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


void solve()
{
    memset(dp, 0x80, sizeof(dp));
    int C = MAXSF * N;
    int R = C * 2 + 10;
    dp[C] = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] < 0) {
            for (int j = S[i]; j - S[i] <= R; j++) {
                dp[j] = max(dp[j], dp[j-S[i]] + F[i]);
            }
        }
        else {
            for (int j = R; j >= S[i]; j--) {
                dp[j] = max(dp[j], dp[j-S[i]] + F[i]);
            }
        }
    }
    int m = -R;
    for (int i = C; i  <= R; i++) {
        if (dp[i] >= 0) m = max(m, i - C + dp[i]);
    }
    printf("%d\n", m);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &S[i], &F[i]);
        }

        solve();
    }
}
