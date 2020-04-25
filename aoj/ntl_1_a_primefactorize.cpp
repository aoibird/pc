#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000000000+10;
bool V[MAXN];
// vector<int> prime;
vector<int> factor;

int main()
{
  int n; scanf("%d", &n);
  int on = n;
  for (int i = 2; i*i <= on; i++) {
    if (!V[i]) {
      // prime.push_back(i);
      for (int j=i*i; j <= n; j += i) {
        V[j] = true;
      }
      // printf("%d %d\n", i, n);
      while (n % i == 0) { factor.push_back(i); n /= i; }
    }
  }
  // for (int i = 0; i <= n; i++) printf("%d:%d%c", i, V[i], i==n?'\n':' ');
  if (factor.empty()) {
    printf("%d: %d\n", on, on);
  }
  else {
    printf("%d:", on);
    for (int i = 0; i < factor.size(); i++) printf(" %d", factor[i]);
    printf("\n");
  }
}
