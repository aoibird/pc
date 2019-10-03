// POJ 2429
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
  ll g, l;
  while (scanf("%lld%lld", &g, &l) == 2) {
    ll ab = g * l;
    ll best = g * l;
    ll best_a, best_b;
    //printf("%lld\n", best);
    for (ll i = 1; i*i <= ab; i++) {
      ll q = ab/i;
      ll r = ab%i;
      //printf("%lld / %lld = %lld ... %lld\n", ab, i, q, r);
      if (r == 0 && (i + q < best)) {
        best = i + q;
        best_a = i;
        best_b = q;
      }
    }
    if (best_a > best_b) swap(best_a, best_b);
    printf("%lld %lld\n", best_a, best_b);
  }
}
