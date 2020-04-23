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
  int l, r;
  scanf("%d%d", &l, &r);
  printf("YES\n");
  for (int i = l; i <= r-1; i+=2) {
    printf("%d %d\n", i, i+1);
  }
}
