// POJ 1258
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int INF = 10000000;
const int MAXN = 100+10;
int N; // [3, 100]
vector<PII> G[MAXN];
int D[MAXN];
int S;

void prim()
{
  fill(D, D+N, INF);
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  D[0] = 0;
  pq.push(PII(0, 0));
  S = 0;
  while (!pq.empty()) {
    PII curr = pq.top(); pq.pop();
    int c = curr.first;
    int v = curr.second;
    if (c > D[v]) continue;
    S += c;
    for (int u = 0; u < G[v].size(); u++) {
      PII x = G[v][u]; int to = x.first; int cost = x.second;
      if (D[to] > cost) {
        D[to] = cost;
        pq.push(PII(D[to], to));
      }
    }
  }
}

int main()
{
  while (scanf("%d", &N) == 1) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int c; scanf("%d", &c);
        if (c != 0) G[i].push_back(PII(j, c));
      }
    }

    prim();

    printf("%d\n", S);
    for (int i = 0; i < N; i++) G[i].clear();
  }
}
