#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXV 5050
#define INF 100050
using namespace std;

typedef pair<int, int> P;
struct edge { int to; int weight; };
vector<edge> G[MAXV];
int dist[MAXV];
int dist2[MAXV];
int n, r;

void input()
{
  scanf("%d%d", &n, &r);
  for (int i = 0; i < r; i++) {
    int from, to, weight;
    scanf("%d%d%d", &from, &to, &weight);
    G[from-1].push_back({to-1, weight});
    G[to-1].push_back({from-1, weight});
  }
}

void dijkstra(int s)
{
  priority_queue<P, vector<P>, greater<P> > pq;
  fill(dist, dist+n, INF);
  fill(dist2,dist2+n, INF);
  dist[s] = 0;
  pq.push(P(0, s));

  while (!pq.empty()) {
    P p = pq.top(); pq.pop();
    int d = p.first;
    int v = p.second;
    if (dist[v] < p.first) continue;

    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      int d2 = d + e.weight;
      if (dist[e.to] > d2) {
        //swap(dist[e.to], d2);
        dist[e.to] = d2;
        pq.push(P(dist[e.to], e.to));
      }
      if (dist2[e.to] > d2 && dist[e.to] < d2) {
        dist2[e.to] = d2;
        pq.push(P(dist2[e.to], e.to));
      }
    }
  }

  printf("%d\n", dist2[n-1]);
}

int main()
{
  input();
  dijkstra(0);
}
