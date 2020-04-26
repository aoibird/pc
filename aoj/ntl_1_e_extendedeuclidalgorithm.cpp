#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

void exgcd(int a, int b, int& d, int& x, int& y)
{
  if (b == 0) { d = a; x = 1; y = 0; }
  else { exgcd(b, a%b, d, y, x);  y -= (a/b)*x; }
}

int main()
{
  int a, b; scanf("%d%d", &a, &b);
  int d, x, y;
  exgcd(a, b, d, x, y);
  printf("%d %d\n", x, y);
}
