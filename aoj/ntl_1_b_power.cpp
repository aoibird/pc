#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll power(ll x, ll n, ll m)
{
  ll f = 1; x %= m;
  for ( ; n > 0; n>>=1) {
    if (n&1) f=f*x%m;
    x=x*x%m;
  }
  return f;
}

int main()
{
  int x, n; scanf("%d%d", &x, &n);
  ll m = 1000000007;
  printf("%lld\n", power(x, n, m));
}
