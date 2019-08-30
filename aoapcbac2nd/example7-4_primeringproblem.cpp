// UVa 524
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 20;
int A[MAXN];
int V[MAXN];
int N; // <= 16

int isprime(int x)
{
  for (int i = 2; i*i <= x; i++) {
    if (x % i == 0) return 0;
  }

  return 1;
}

void dfs(int curr)
{
  if (curr == N+1 && isprime(A[N] + A[1])) {
    for (int i = 1; i <= N; i++) {
      printf("%d", A[i]);
      if (i == N) printf("\n");
      else printf(" ");
    }
  }
  else {
    for (int i = 2; i <= N; i++) {
      if (!V[i] && isprime(A[curr-1] + i)) {
        A[curr] = i;
        V[i] = 1;
        dfs(curr+1);
        V[i] = 0;
      }
    }
  }
}

int main()
{
  int T = 1;
  while (scanf("%d", &N) == 1) {
    if (T != 1) printf("\n");
    printf("Case %d:\n", T);
    A[1] = 1;
    memset(V, 0, sizeof(V));
    dfs(2);

    T++;
  }

}
