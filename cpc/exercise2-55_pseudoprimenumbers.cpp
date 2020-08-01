// POJ 3641
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> PII;


ll power(ll x, ll n, ll mod)
{
    ll s = 1;
    while (n) { if (n&1) { s = s*x%mod; } x = x*x%mod; n>>=1; }
    return s;
}

bool isprime(ll x)
{
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    ll a, p;
    while (scanf("%lld%lld", &p, &a) == 2) {
        if (a == 0 && p == 0) break;
        if (isprime(p)) { printf("no\n"); }
        else {
            ll x = power(a, p, p);
            // printf("%d ^ %d = %lld\n", a, p, x);
            if (x == a) printf("yes\n");
            else printf("no\n");
        }
    }
}
