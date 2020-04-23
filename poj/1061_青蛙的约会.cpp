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
  scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L);

  ll a = ((m-n) + L) % L;
  ll b = ((y-x) + L) % L;
  ll d = 0, k = 0, g = 0;
  ll thegcd = gcd(a, L);
  // printf("%lld k - %lld g = %lld\n", a, L, b);
  if (y == x) printf("0\n");
  else if (m == n) printf("Impossible\n");
  else if (b % thegcd != 0) printf("Impossible\n");
  else { exgcd(a, L, d, k, g); printf("%lld\n", (k*(b/thegcd) + L) % L); }
}
