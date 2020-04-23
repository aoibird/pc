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

vector<int> divisors;

int main()
{
  ll g, l;
  while (scanf("%lld%lld", &g, &l) == 2) {
    ll mul = l / g;
    ll best = 1LL << 62;
    ll a, b = 0;
    for (ll i = 2; i*i <= mul; i++) {
      // printf("i: %lld\n", i);
      if (mul % i == 0) {
        divisors.push_back(i); divisors.push_back(mul / i);
        if (i + mul/i < best) { a = i; b = mul/i; best = a + b; }
      }
    }
    if (a > b) swap(a, b);
    printf("%lld %lld\n", a*g, b*g);
  }
}
