// LOJ 6004 「网络流 24 题」圆桌聚餐
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
typedef unsigned int uint;

const int MAXM = 150+5;
const int MAXN = 270+5;
const int MAXV = MAXM + MAXN + 2;
const int INF = 1e9;

struct Edge {
    int to; ll cap; int rev;
    Edge(int t=0, ll c=0, int r=0) { to=t, cap=c, rev=r; }
};

vector<Edge> G[MAXV];
int V, M, N, S, T;

int level[MAXV], iter[MAXV];
void add_edge(int from, int to, ll cap) {
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0, q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (uint i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1; q.push(e.to);
            }
        }
    }
}

ll dfs(int v, int t, ll f) {
    if (v == t) return f;
    for (uint i = iter[v]; i < G[v].size(); i++) {
        Edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) { e.cap -= d; G[e.to][e.rev].cap += d; return d; }
        }
    }
    return 0;
}

ll max_flow(int s, int t) {
    ll flow = 0;
    while (true) {
        bfs(s);
        if (level[t] < 0) { return flow; }
        memset(iter, 0, sizeof(iter));
        ll f; while ((f = dfs(s, t, INF)) > 0) { flow += f; }
    }
}

int main()
{
    while (scanf("%d%d", &M, &N) == 2) {
        V = M + N + 2, S = 0, T = M + N + 1;
        for (int i = 0; i < V; i++) { G[i].clear(); }

        ll sum = 0;
        for (int i = 1; i <= M; i++) {
            int r; scanf("%d", &r); sum += r;
            add_edge(S, i, r);
            for (int j = 1; j <= N; j++) { add_edge(i, M+j, 1); }
        }
        for (int i = 1; i <= N; i++) {
            int c; scanf("%d", &c);
            add_edge(M+i, T, c);
        }

        ll flow = max_flow(S, T);
        printf("%d\n", (int) flow == sum);
        if (flow == sum) {
            for (int i = 1; i <= M; i++) {
                vector<int> to;
                for (uint j = 0; j < G[i].size(); j++) {
                    Edge &e = G[i][j];
                    if (e.cap == 0) to.push_back(e.to);
                }
                for (uint j = 0; j < to.size(); j++) {
                    printf("%d%c", to[j]-M, j+1==to.size()?'\n':' ');
                }
            }
        } else {}
    }
}
