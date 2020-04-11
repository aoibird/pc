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
  int T;
  int f, a, c;
  scanf("%d%d%d", &f, &a, &T);
  for (int i = 0; i < T; i++) {
    scanf("%d", &c);
    if (c <= 1000) printf("%d %d\n", c, c*f);
    else printf("%d %d\n", c, 1000*f + (c-1000)*a);
  }
}
