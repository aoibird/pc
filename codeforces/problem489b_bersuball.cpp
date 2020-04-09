#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXNM = 100+10;
const int INF = 1000000000;
int B[MAXNM];
int G[MAXNM];
int N, M;

struct Edge {
  int to, cap, rev;
  Edge(int t=0, int c=0, int r=0) { to=t; cap=c; rev=r; }
};

vector<Edge> GR[MAXNM*2];
bool V[MAXNM*2];

void add_edge(int from, int to, int cap)
{
  GR[from].push_back(Edge(to, cap, GR[to].size()));
  GR[to].push_back(Edge(from, 0, GR[from].size()-1));
}

int dfs(int v, int t, int f)
{
  if (v == t) return f;
  V[v] = true;
  for (int i = 0; i < GR[v].size(); i++) {
    Edge &e = GR[v][i];
    if (!V[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap = -d;
        GR[e.to][e.rev].cap -= d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t)
{
  int flow = 0;
  while (true) {
    memset(V, 0, sizeof(V));
    int f = dfs(s, t, INF);
    if (f == 0) return flow;
    flow += f;
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &B[i]);
  scanf("%d", &M);
  for (int i = 0; i < M; i++) scanf("%d", &G[i]);

  int s = N+M;
  int t = s+1;
  for (int i = 0; i < N; i++) add_edge(s, i, 1);
  for (int i = 0; i < M; i++) add_edge(N+i, t, 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (abs(B[i] - G[j]) <= 1) add_edge(i, N+j, 1);
    }
  }

  printf("%d\n", max_flow(s, t));
}
