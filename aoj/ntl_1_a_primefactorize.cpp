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
vector<int> prime;
vector<int> factor;

int main()
{
  int n; scanf("%d", &n);
  int on = n;
  for (int i = 2; i <= on && n != 1; i++) {
    if (!V[i]) {
      prime.push_back(i);
      while (n % i == 0) { factor.push_back(i); n /= i; }
    }
    for (int j = 0; j < prime.size() && i*prime[j] <= on; j++) {
      V[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }

  printf("%d:", on);
  for (int i = 0; i < factor.size(); i++) printf(" %d", factor[i]);
  printf("\n");
}
