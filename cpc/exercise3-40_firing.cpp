// POJ 2987 Firing
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

const int MAXN = 5000+5;
// const int MAXM = 60000+5;
const ll INF = 1LL << 40;
int N, M;

const int MAXV = MAXN + 2;
struct Edge {
    int to; ll cap; int rev;
    Edge(int t=0, ll c=0, int r=0) { to=t; cap=c; rev=r; }
};
int V;
vector<Edge> G[MAXV];
int level[MAXV], iter[MAXV];

void add_edge(int from, int to, ll cap)
{
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}

void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0; q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1; q.push(e.to);
            }
        }
    }
}

ll dfs(int v, int t, ll f)
{
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
        Edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) { e.cap -= d; G[e.to][e.rev].cap += d; return d; }
        }
    }
    return 0;
}

ll max_flow(int s, int t)
{
    ll flow = 0;
    while (true) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        ll f; while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
}

int vis[MAXN]; // -1 visit 0 unvisited 1 accessible
int access(int v, int t)
{
    if (vis[v] != 0) return vis[v];
    if (v == t) return vis[v] = 1;

    int yes = 0; vis[v] = -1;
    for (int i = 0; i < G[v].size(); i++) {
        if (vis[G[v][i].to] != -1 && G[v][i].cap > 0) {
            int x = access(G[v][i].to, t);
            if (x == 1) { yes = 1; break; }
        }
    }
    return vis[v] = yes;
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < MAXV; i++) G[i].clear();

        ll sum = 0;
        int s = N; int t = s+1; V = N+2;
        for (int i = 0; i < N; i++) {
            int x; scanf("%d", &x);
            if (x < 0) { add_edge(s, i, -x); }
            else { add_edge(i, t, x); sum += x; }
        }
        for (int i = 0; i < M; i++) {
            int a, b; scanf("%d%d", &a, &b); a--; b--;
            add_edge(b, a, INF);
        }

        ll flow = max_flow(s, t);
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < N; i++) access(i, t);
        for (int i = 0; i < N; i++) if (vis[i] == 1) cnt++;
        printf("%d %lld\n", cnt, sum-flow);
    }
}
