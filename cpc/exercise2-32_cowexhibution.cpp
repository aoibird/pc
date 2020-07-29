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

struct Result {
    int t, ts, tf;
    Result(int ti=0, int tsi=0, int tfi=0) { t=ti; ts=tsi; tf=tfi; }
};

const int MAXN = 100+10;
const int MAXT = 1e5 + 10;
int T[MAXN];
int S[MAXN];
int F[MAXN];
bool dp[MAXT];
Result res[MAXT];
int N;
int MT;

void print_array(bool *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


void solve()
{
    dp[0] = true;
    for (int i = 0; i < N; i++) {
        for (int j = MT; j >= T[i]; j--) {
            if (!dp[j] && T[i] >= 0 && dp[j-T[i]]) {
                dp[j] = true;
                Result &x = res[j-T[i]];
                res[j] = Result(x.t + T[i], x.ts + S[i], x.tf + F[i]);
            }
        }
        // print_array(dp, MT+1);
    }
    int m = 0;
    for (int i = MT; i >= 0; i--) {
        if (dp[i] && res[i].ts >= 0 && res[i].tf >= 0) { m = i; break; }
    }
    printf("%d\n", m);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        MT = 0;
        memset(dp, 0, sizeof(dp));
        memset(res, 0, sizeof(res));
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &S[i], &F[i]);
            T[i] = S[i] + F[i];
            if (T[i] > 0) MT += T[i];
        }

        solve();
    }
}
