// UVa 11636
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
  int n; // [1, 10000]
  int tc = 1;
  while (scanf("%d", &n) == 1) {
    if (n <= 0) break;
    printf("Case %d: %d\n", tc, (int)ceil(log2(n)));
    tc++;
  }
}
