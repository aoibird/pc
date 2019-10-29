// UVa 1149
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000+10;
int A[MAXN];
int N;
int M;

int solve()
{
  int sum = 0;
  sort(A, A+N);
  //for (int i = 0; i < N; i++) printf("%d ", A[i]); printf("\n");
  int i = 0, j = N-1;
  while (i <= j) {
    if (A[i] + A[j] > M) { sum += 1; j--; }
    else { sum += 1; i++; j--; }
  }
  return sum;
}

void input()
{
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d", A+i);
}

int main()
{
  int T; scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    input();
    int res = solve();
    printf("%d\n", res);
    if (i != T-1) printf("\n");
  }
}
