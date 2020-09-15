// POJ 2195 Going Home
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

const int MAXR = 100+5;
const int MAXC = 100+5;
const int MAXN = MAXR*MAXC+5;
int R, C, N;
vector<PII> H;
vector<PII> M;

const int INF = 0x3f3f3f3f;
const int MAXV = MAXN*2+2;
struct Edge {
    int to, cap, cost, rev;
    Edge(int t=0, int c=0, int co=0, int r=0) { to=t; cap=c; cost=co; rev=r; }
};
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
    fill(dist, dist+V, INF); dist[s] = 0; pq.push(PII(0, s));
    while (!pq.empty()) {
        PII p = pq.top(); pq.pop();
        int v = p.second, d = p.first;
        if (dist[v] < d) continue;
        for (int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v]-h[e.to]) {
                dist[e.to] = dist[v] + e.cost + h[v]-h[e.to];
                prevv[e.to] = v; preve[e.to] = i;
                pq.push(PII(dist[e.to], e.to));
            }
        }
    }
}

int min_cost_flow(int s, int t, int f)
{
    int res = 0;
    fill(h, h + V, 0);
    while (f > 0) {
        dijkstra(s);
        if (dist[t] == INF) return -1;
        for (int v = 0; v < V; v++) h[v] += dist[v];
        int d = f;
        for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d; res += d * h[t];
        for (int v = t; v != s; v = prevv[v]) {
            Edge &e = G[prevv[v]][preve[v]];
            e.cap -=d; G[v][e.rev].cap += d;
        }
    }
    return res;

}

void solve()
{
    int s = 2*N, t = 2*N+1;
    V = N*2 + 2;
    for (int i = 0; i < V; i++) G[i].clear();
    for (int i = 0; i < N; i++) { // man i
        for (int j = 0; j < N; j++) { // house j
            add_edge(i, j+N, 1, abs(M[i].first-H[j].first)+abs(M[i].second-H[j].second));
        }
    }
    for (int i = 0; i < N; i++) add_edge(s, i, 1, 0);
    for (int i = 0; i < N; i++) add_edge(i+N, t, 1, 0);


    int res = min_cost_flow(s, t, N);
    printf("%d\n", res);
}

int main()
{
    while (scanf("%d%d", &R, &C) == 2 && R && C) {
        N = 0; H.clear(); M.clear();

        int ch; while ((ch = getchar()) != EOF && ch != '\n') ;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                ch = getchar();
                if (ch == 'm') { M.push_back(PII(i, j)); N++; }
                else if (ch == 'H') { H.push_back(PII(i, j)); }
                else ;
            }
            getchar();
        }

        solve();
    }
}
