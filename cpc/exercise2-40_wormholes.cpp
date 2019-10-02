// POJ 3259
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
  int from, to, cost;
  Edge(int f=0, int t=0, int c=0) { from=f; to=t; cost=c; }
};
//const int INF = 1 << 30;
const int MAXN = 500+10;
const int MAXM = 2500+10;
const int MAXW = 200+10;
const int MAXE = MAXM*2 + MAXW;
Edge ES[MAXE];
int D[MAXN];
int E;
int N; // [1, 500]
int M; // [1, 2500]
int W; // [1, 200]

bool bellman_ford()
{
  memset(D, 0, sizeof(D));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < E; j++) {
      Edge e = ES[j];
      if (D[e.to] > D[e.from] + e.cost) {
        D[e.to] = D[e.from] + e.cost;
        if (i == N-1) return true;
      }
    }
  }
  return false;
}

void input()
{
  scanf("%d%d%d", &N, &M, &W);
  E = 0;
  for (int i = 0; i < M; i++) {
    int s, e, t; scanf("%d%d%d", &s, &e, &t);
    s -= 1; e -= 1;
    //G[s][e] = t;
    //G[e][s] = t;
    ES[E++] = Edge(s, e, t);
    ES[E++] = Edge(e, s, t);
  }
  for (int i = 0; i < W; i++) {
    int s, e, t; scanf("%d%d%d", &s, &e, &t);
    s -= 1; e -= 1;
    //G[s][e] = -t;
    ES[E++] = Edge(s, e, -t);
  }
  //printf("E = %d\n", E);
}

int main()
{
  int T; scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    input();
    if (bellman_ford()) printf("YES\n");
    else printf("NO\n");
  }
}
