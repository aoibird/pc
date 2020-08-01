// POJ 1995
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


ll power(ll x, ll n, ll mod)
{
    ll s = 1;
    while (n) { if (n&1) s = s*x%mod; x = x*x%mod; n >>= 1; }
    return s;
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        int M, H; scanf("%d%d", &M, &H);
        ll sum = 0;
        for (int i = 0; i < H; i++) {
            ll a, b; scanf("%lld%lld", &a, &b);
            sum = (sum + power(a, b, M)) % M;
        }
        printf("%lld\n", sum);
    }
}
