// UVa 11572
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 1000000;
int A[MAXN+10];
int N;
int R, L;
set<int> V;

void input()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", A+i);
}

bool isin(int x)
{
  for (int i = R; i <= L; i++)
    if (A[i] == x) return true;
  return false;
}

int solve()
{
  int best = 0;
  R = L = 0;
  V.clear();
  while (L < N) {
    while (R < N && V.count(A[R]) == 0) { V.insert(A[R]); R++; }
    best = max(best, R-L);
    V.erase(A[L]);
    L++;
  }

  return best;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    input();
    int res = solve();
    printf("%d\n", res);
  }
}
