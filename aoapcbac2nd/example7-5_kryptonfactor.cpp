#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 90;
int A[MAXN];
int N; // (0, 80]
int L; // [1, 26]
int cnt;

int valid(int curr)
{
  for (int j = 1; j*2 <= curr+1; j++) {
    int eq = 1;
    for (int t = 0; t < j; t++) {
      if (A[curr-t] != A[curr-t-j]) {
        eq = 0;
        break;
      }
    }
    if (eq) return 0;
  }

  return 1;
}


int dfs(int curr)
{
  if (cnt == N) {
    for (int i = 0; i < curr; i++) {
      if (i != 0 && i % 64 == 0) printf("\n");
      else if (i != 0 && i % 4 == 0) printf(" ");
      printf("%c", A[i]);
    }
    printf("\n%d\n", curr);

    return 0;
  }
  else {

    for (int i = 0; i < L; i++) {
      // for (int i = 0; i < curr; i++) printf("%c", A[i]);
      // printf(" %d %c %d", curr, i+'A', valid(curr));
      // printf("\n");

      A[curr] = i+'A';
      if (valid(curr)) {
        cnt++;
        int cont = dfs(curr+1);
        if (!cont) return 0;
      }
    }

    return 1;
  }
}

void input()
{
  ;
}

int main()
{
  while (scanf("%d%d", &N, &L) == 2) {
    //printf("%d %d\n", N, L);
    cnt = 1;
    A[0] = 'A';
    dfs(1);
  }
}
