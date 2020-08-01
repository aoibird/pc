// AOJ 0005
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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ll a, b;
    while (scanf("%lld%lld", &a, &b) == 2) {
        ll g = gcd(a, b);
        ll l = a / g * b;
        printf("%lld %lld\n", g, l);
    }
}
