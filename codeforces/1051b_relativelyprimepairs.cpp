#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  long long l, r;
  scanf("%lld%lld", &l, &r);
  printf("YES\n");
  for (long long i = l; i <= r-1; i+=2) {
    printf("%lld %lld\n", i, i+1);
  }
}
