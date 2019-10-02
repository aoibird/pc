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
      PII e = G[v][u];
      if (D[e.first] > e.second) {
        D[e.first] = e.second;
        pq.push(PII(D[e.first], e.first));
      }
    }
  }
}

int main()
{
  int ch;
  while ((ch = getchar()) != EOF) {
    ungetc(ch, stdin);
    if (scanf("%d", &N) != 1) break;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int c; scanf("%d", &c);
        if (c != 0) G[i].push_back(PII(j, c));
      }
    }

    prim();

    printf("%d\n", S);
  }
}
