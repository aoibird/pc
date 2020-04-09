#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200+10;
const int MAXM = 200+10;
bool G[MAXN][MAXM];
int MA[MAXM];
bool V[MAXM];
int N, M;

void input()
{
  for (int i = 1; i <= N; i++) {
    // printf("i: %d\n", i);
    int c; scanf("%d", &c);
    for (int j = 1; j <= c; j++) {
      int x;
      scanf("%d", &x);
      G[i][x] = true;
    }
  }
}

bool find(int x)
{
  for (int i = 1; i <= M; i++) {
    if (G[x][i] && !V[i]) {
      V[i] = true;
      if (!MA[i] || find(MA[i])) {
        MA[i] = x;
        return true;
      }
    }
  }

  return false;
}

void solve()
{
  int sum = 0;
  for (int x = 1; x <= N; x++) {
    memset(V, 0, sizeof(V));
    if (find(x)) sum++;
  }
  printf("%d\n", sum);
  // for (int i = 1; i <= M; i++) {
  //   printf("%d ", MA[i]);
  // }
  // printf("\n");
}

int main()
{
  while (scanf("%d%d", &N, &M) > 0) {
    memset(G, 0, sizeof(G));
    memset(MA, 0, sizeof(MA));
    input();
    solve();
  }
}
