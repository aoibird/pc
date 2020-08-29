// POJ 2135 Farm Four
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
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 1000+5;
// const int MAXM = 10000+5;
const int INF = 0x3f3f3f3f;
int N, M;

struct Edge {
    int to, cap, cost, rev;
    Edge(int t=0, int c=0, int co=0, int r=0) { to=t; cap=c; cost=co; rev=r; }
};
const int MAXV = MAXN;
int V;
vector<Edge> G[MAXV];
int h[MAXV], dist[MAXV], prevv[MAXV], preve[MAXV];

void add_edge(int from, int to, int cap, int cost)
{
    G[from].push_back(Edge(to, cap, cost, G[to].size()));
    G[to].push_back(Edge(from, 0, -cost, G[from].size()-1));
}

void dijkstra(int s)
{
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    fill(dist, dist+V, INF);
    dist[s] = 0; pq.push(PII(0, s));
    while (!pq.empty()) {
        PII p = pq.top(); pq.pop();
        int d = p.first, v = p.second;
        if (dist[v] < d) continue;
        for (int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]) {
                dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
                prevv[e.to] = v; preve[e.to] = i;
                pq.push(PII(dist[e.to], e.to));
            }
        }
    }
}

int min_cost_flow(int s, int t, int f)
{
    int cost = 0; fill(h, h+V, 0);
    while (f > 0) {
        dijkstra(s);
        if (dist[t] == INF) return -1;
        for (int v = 0; v < V; v++) h[v] += dist[v];
        int d = f;
        for (int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        cost += d * h[t];
        for (int v = t; v != s; v = prevv[v]) {
            Edge &e = G[prevv[v]][preve[v]];
            e.cap -= d; G[v][e.rev].cap += d;
        }
    }
    return cost;
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        V = N;
        int s = 0, t = N-1;
        for (int i = 0; i < M; i++) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            add_edge(a-1, b-1, 1, c); add_edge(b-1, a-1, 1, c);
        }

        printf("%d\n", min_cost_flow(s, t, 2));
    }
}
