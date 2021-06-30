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
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int P = 998244352;
const int MAXN = 5000000+10;
int A[MAXN];
ll R[MAXN];
int X, N;

// x^n % m
ll power(ll x, ll n, ll m)
{
    ll f = 1;
    for (x %= m; n > 0; n>>=1, x=x*x%m) { if (n&1) f=f*x%m; }
    return f;
}

void calc(int left, int right)
{
    R[right] = power(X, A[right], P);
    for (int i = right-1; i >= left; i--) {
        R[i] = (R[i+1] == 0) ? power(X, A[i], P)
            : R[i+1] * power(X, A[i]-A[i+1], P) % P;
    }
}


int main()
{
    while (scanf("%d%d", &X, &N) == 2) {
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]); }

        R[0] = power(X, A[0], P);
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (i == N) {
                if (count != 0) { calc(i-count, i-1); count = 0; }
            }
            else if (A[i] >= A[i-1]) {
                if (count != 0) { calc(i-count, i-1); count = 0; }
                R[i] = (R[i-1] == 0) ? power(X, A[i], P) : R[i-1] * power(X, A[i]-A[i-1], P) % P;
            } else {
                count++;
            }
        }

        // for (int i = 0; i < N; i++) { printf("%d%c", R[i], i+1==N?'\n':' '); }
        for (int i = 0; i < N; i++) { printf("%lld ", R[i]); }
    }
}
