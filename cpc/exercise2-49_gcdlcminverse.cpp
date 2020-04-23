// POJ 2429
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
  ll g, l;
  while (scanf("%lld%lld", &g, &l) == 2) {
    ll mul = l / g;
    //ll best = 1LL << 62;
    ll a = 0, b = 0;
    // printf("%lld\n", (ll)sqrt(mul));
    for (ll i = (ll)sqrt((long double)mul); i >= 2; i--) {
      // printf("i: %lld\n", i);
      if (mul % i == 0) { a = i; b = mul/i; break; }
    }
    if (a > b) swap(a, b);
    printf("%lld %lld\n", a*g, b*g);
  }
}
