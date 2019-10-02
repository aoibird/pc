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
bool IN[MAXN];
int S;

void prim()
{
  fill(D, D+N, INF);
  fill(IN, IN+N, false);
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  D[0] = 0;
  pq.push(PII(0, 0));
  //IN[0] = true;
  S = 0;
  while (!pq.empty()) {
    PII curr = pq.top(); pq.pop();
    int c = curr.first;
    int v = curr.second;
    if (c > D[v] || IN[v] == true) continue;
    IN[v] = true;
    S += D[v];
    for (int i = 0; i < G[v].size(); i++) {
      int u = G[v][i].first;
      if (D[u] > G[v][i].second) {
        D[u] = G[v][i].second;
        pq.push(PII(D[u], u));
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
        //G[i][j] = c;
        G[i].push_back(PII(j, c));
      }
    }

    prim();

    printf("%d\n", S);
    for (int i = 0; i < N; i++) G[i].clear();
  }
}
