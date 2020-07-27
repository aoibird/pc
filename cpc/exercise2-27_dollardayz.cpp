// POJ 3181
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

const ll MOD = 1e18;

struct BigInt {
    ll hi, lo;
    BigInt(): hi(0), lo(0) {}
    BigInt(int a) { hi = 0; lo = a; }
    void operator+=(BigInt &a) {
        lo += a.lo;
        if (lo >= MOD) { lo -= MOD; hi += 1; }
        hi += a.hi;
    }
    void print() {
        if (hi) printf("%lld%018lld\n", hi, lo);
        else printf("%lld\n", lo);
    }
};

const int MAXN = 1000+10;
BigInt dp[MAXN];
int N, K;

void solve()
{
    for (int i = 0; i <= N; i++) dp[i] = BigInt(1);
    for (int j = 2; j <= K; j++) {// price $j ~ [1, K]
        for (int i = 1; i <= N; i++) {// i dollars ~ [1, N]
            if (i-j >= 0) dp[i] += dp[i-j];
        }
    }
}

int main()
{
    while (scanf("%d%d", &N, &K) == 2) {
        if (N == 0 && K == 0) break;
        memset(dp, 0, sizeof(dp));
        solve();
        dp[N].print();
    }
}
