// UVa 11054
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N; // [2, 100000]

int main()
{
  while (scanf("%d", &N) == 1) {
    if (N == 0) break;

    ll sum = 0, last = 0;
    for (int i = 0; i < N; i++) {
      ll a;
      scanf("%lld", &a);
      sum += abs(last);
      last += a;
    }

    printf("%lld\n", sum);
  }
}
