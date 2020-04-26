#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 20;
int a[MAXN];

int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a%b);
}

int main()
{
  int n; scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  for (int i = 1; i < n; i++) {
    int g = gcd(a[i-1], a[i]);
    int l = a[i-1]/g*a[i];
    a[i] = l;
  }
  printf("%d\n", a[n-1]);
}
