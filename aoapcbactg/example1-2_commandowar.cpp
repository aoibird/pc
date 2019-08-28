// UVa 11729
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;

const int MAXN = 1000;
PII A[MAXN+5]; // [1, 10000]
int N; // [1, 1000]

int solve()
{
  sort(A, A+N);
  int sum = 0;
  int curr = 0;
  for (int i = N-1; i >= 0; i--) {
    int j = A[i].first;
    int b = A[i].second;

    curr += b;
    sum = max(sum, curr+j);
  }
  return sum;
}

int main()
{
  int tc = 1;
  while (scanf("%d", &N) == 1) {
    if (N == 0) break;
    for (int i = 0; i < N; i++) {
      int b, j;
      scanf("%d%d", &b, &j);
      A[i] = PII(j, b);
    }

    int res = solve();

    printf("Case #%d: %d\n", tc, res);
    tc++;
  }

}
