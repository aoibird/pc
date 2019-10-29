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

  priority_queue<PII, vector<PII>, greater<PII> > pq;
  pq.push(PII(MINCOST[0], 0));
  while (!pq.empty()) {
    PII p = pq.top(); pq.pop();
    int curr = p.second;
    int cost = p.first;
    if (V[curr] || cost > MINCOST[curr]) continue;

    V[curr] = true;
    sum += cost;

    for (int i = 0; i < N; i++) {
      if (G[curr][i] < MINCOST[i]) {
        MINCOST[i] = G[curr][i];
        pq.push(PII(MINCOST[i], i));
      }
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
