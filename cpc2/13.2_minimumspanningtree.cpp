// AOJ ALDS1_12_A
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int INF = 100000;
const int MAXN = 100+10;
int G[MAXN][MAXN];
int MINCOST[MAXN];
bool V[MAXN];
int N;

int prim()
{
  for (int i = 0; i < N; i++) { MINCOST[i] = INF; V[i] = false; }
  MINCOST[0] = 0;
  int sum = 0;

  while (true) {
    int curr = -1, i = 0;
    for ( ; i < N; i++) if (!V[i]) { curr = i; break; }
    for ( ; i < N; i++) if (!V[i] && MINCOST[i] < MINCOST[curr]) curr = i;

    if (curr == -1) break;
    V[curr] = true;
    sum += MINCOST[curr];

    for (int i = 0; i < N; i++) {
      MINCOST[i] = min(MINCOST[i], G[curr][i]);
    }
  }

  return sum;
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &G[i][j]);
      if (G[i][j] == -1) G[i][j] = INF;
    }
  }

  int res = prim();
  printf("%d\n", res);
}
