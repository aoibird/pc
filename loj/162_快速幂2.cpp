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
typedef pair<int, ll> PIL;

const int P = 998244352;
const int MAXN = 5000000 + 10;
PII A[MAXN];
PII R[MAXN];

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
            int a;
            scanf("%d", &a);
            A[i] = PII(a, i);
        }

        sort(A, A + N);

        ll f = 1;

        for (int i = 0; i < N; i++) {
            int d = (i == 0) ? A[i].first : A[i].first - A[i - 1].first;
            f = (d > 0) ? f * power(X, d, P) : f;
            R[i] = PII(A[i].second, f);
        }

        sort(R, R + N);

        for (int i = 0; i < N; i++) {
            printf("%d%c", R[i].second, (i + 1 == N) ? '\n' : ' ');
        }
    }
}
