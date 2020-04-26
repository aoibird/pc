#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> factor;

int main()
{
  int n; scanf("%d", &n);
  int on = n;
  for (int i = 2; i*i <= n; i++) {
    while (n % i == 0) { factor.push_back(i); n /= i; }
  }
  if (n != 1) factor.push_back(n);

  printf("%d:", on);
  for (int i = 0; i < factor.size(); i++) printf(" %d", factor[i]);
  printf("\n");
}
