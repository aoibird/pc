// POJ 3281 Dining
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

const int MAXN = 100+5;
const int MAXD = 100+5;
const int MAXF = 100+5;
bool likefood[MAXN][MAXF], likedrink[MAXN][MAXD];
int N, F, D;

struct Edge {
    int to, cap, rev;
    Edge(int t=0, int c=0, int r=0) { to=t; cap=c; rev=r; }
};
const int INF = 1000000;
const int MAXV = 2 * MAXN + MAXD + MAXF + 10;
vector<Edge> G[MAXV];
int level[MAXV], iter[MAXV];

void add_edge(int from, int to, int cap)
{
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}

void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> q; level[s] = 0; q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1; q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
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

int max_flow(int s, int t)
{
    int flow = 0;
    for (;;) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f; while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
}

void solve()
{
    // s -> food -> cow -> cow -> drink -> t
    int s = N*2+F+D; int t = s+1;
    for (int i = 0; i < F; i++) add_edge(s, N*2+i, 1); // s -> food
    for (int i = 0; i < D; i++) add_edge(N*2+F+i, t, 1); // drink -> t
    for (int i = 0; i < N; i++) { // food -> cow -> cow -> drink
        add_edge(i, N+i, 1);
        for (int j = 0; j < F; j++)
            if (likefood[i][j]) add_edge(N*2+j, i, 1);
        for (int j = 0; j < D; j++)
            if (likedrink[i][j]) add_edge(N+i, N*2+F+j, 1);
    }

    printf("%d\n", max_flow(s, t));
}

int main()
{
    while (scanf("%d%d%d", &N, &F, &D) == 3) {
        memset(likefood, 0, sizeof(likefood));
        memset(likedrink, 0, sizeof(likedrink));
        for (int i = 0; i < N; i++) {
            int f, d; scanf("%d%d", &f, &d);
            while (f-->0) { int x; scanf("%d", &x); likefood[i][x-1] = true; }
            while (d-->0) { int x; scanf("%d", &x); likedrink[i][x-1] = true; }
        }

        solve();
    }
}
