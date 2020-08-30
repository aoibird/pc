// POJ 3686 The Windy's
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

const int MAXN = 50+5;
const int MAXM = 50+5;
const int INF = 0x3f3f3f3f;
int N, M;
int Z[MAXN][MAXM];

struct Edge {
    int to, cap, cost, rev;
    Edge(int t=0, int c=0, int co=0, int r=0) { to=t; cap=c; cost=co; rev=r; }
};
const int MAXV = MAXN + MAXN * MAXM;
int V;
vector<Edge> G[MAXV];
int dist[MAXV], prevv[MAXV], preve[MAXV];

void add_edge(int from, int to, int cap, int cost)
{
    G[from].push_back(Edge(to, cap, cost, G[to].size()));
    G[to].push_back(Edge(from, 0, -cost, G[from].size()-1));
}

void bellman_ford(int s)
{
    fill(dist, dist+V, INF);
    dist[s] = 0;
    bool update = true;
    while (update) {
        update = false;
        for (int v = 0; v < V; v++) {
            if (dist[v] == INF) continue;
            for (int i = 0; i < G[v].size(); i++) {
                Edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    prevv[e.to] = v; preve[e.to] = i;
                    update = true;
                }
            }
        }
    }
}


int min_cost_flow(int s, int t, int f)
{
    int cost = 0;
    while (f > 0) {
        bellman_ford(s);
        if (dist[t] == INF) return -1;
        int d = f;
        for (int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        cost += d * dist[t];
        for (int v = t; v != s; v = prevv[v]) {
            Edge &e = G[prevv[v]][preve[v]];
            e.cap -= d; G[v][e.rev].cap += d;
        }
    }
    return cost;
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int tc=0; tc < TC; tc++) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) scanf("%d", &Z[i][j]);
        }
        for (int i = 0; i < MAXV; i++) G[i].clear();

        int s = N+N*M; int t = s+1;
        V = t+1;
        for (int i = 0; i < N; i++) add_edge(s, i, 1, 0);
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                add_edge(N+j*N+k, t, 1, 0);
                for (int i = 0; i < N; i++) add_edge(i, N+j*N+k, 1, (k+1)*Z[i][j]);
            }
        }

        printf("%.6f\n", (double)min_cost_flow(s, t, N)/N);
    }
}
