// LOJ 162 快速幂 2
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int P = 998244352;
const int MAXN = 5000000 + 10;
int A[MAXN];

// x^n % m
ll power(ll x, ll n, ll m) {
    ll f = 1;

    for (x %= m; n > 0; n >>= 1, x = x * x % m) {
        if (n & 1)
            f = f * x % m;
    }

    return f;
}

int main() {
    int X, N;

    while (scanf("%d%d", &X, &N) == 2) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        ll f = 1;

        for (int i = 0; i < N; i++) {
            int d = (i == 0) ? A[i] : A[i] - A[i - 1];
            f = (d > 0) ? f * power(X, d, P) : (d < 0) ? f / power(X, -d, P) : f;
            printf("%lld%c", f, (i + 1) == N ? '\n' : ' ');
        }
    }
}
