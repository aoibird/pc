// AOJ ALDS1_12_C
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
const int INF = 2000000;
const int MAXN = 10000+10;
vector<PII> G[MAXN];
int D[MAXN];
int N;

void dijkstra(int s)
{
  for (int i = 0; i < N; i++) D[i] = INF;
  D[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII> > pq;
  pq.push(PII(D[s], s));
  while (!pq.empty()) {
    PII p = pq.top(); pq.pop();
    int curr = p.second;
    int cost = p.first;
    if (cost > D[curr]) continue;
    for (int i = 0; i < G[curr].size(); i++) {
      PII e = G[curr][i];
      int t = e.first;
      int c = e.second;
      if (D[t] > D[curr] + c) {
        D[t] = D[curr] + c;
        pq.push(PII(D[t], t));
      }
    }
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int from; scanf("%d", &from);
    int n; scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      int to, cost; scanf("%d%d", &to, &cost);
      G[from].push_back(PII(to, cost));
    }
  }

  dijkstra(0);

  for (int i = 0; i < N; i++) {
    printf("%d %d\n", i, D[i]);
  }
}
