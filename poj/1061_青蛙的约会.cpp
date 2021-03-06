#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b)
{
  return (b == 0) ? a : gcd(b, a % b);
}

void exgcd(ll a, ll b, ll& d, ll& x, ll& y)
{
  if (b == 0) { d = a; x = 1; y = 0; }
  else { exgcd(b, a % b, d, y, x); y -= (a / b) * x; }
}

int main()
{
  ll x, y, m, n, L;
  while (scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L) == 5) {
    ll a = ((m-n)%L + L) % L;
    ll b = ((y-x)%L + L) % L;
    ll d = 0, k = 0, g = 0;
    ll thegcd = gcd(a, L);

    if (m == n || b % thegcd != 0) printf("Impossible\n");
    else { exgcd(a, L, d, k, g); printf("%lld\n", (k*(b/thegcd)%L + L) % L); }
  }
}
