// POJ 3469 Dual Core CPU
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

const int MAXN = 20000+5;
const int MAXM = 200000+5;
const int INF = 2e9;
int N, M;
int A[MAXN], B[MAXN];
PII P[MAXM];
int W[MAXM];

struct Edge {
    int to, cap, rev;
    Edge(int t=0, int c=0, int r=0) { to=t; cap=c; rev=r; }
};
vector<Edge> G[MAXN];
int level[MAXN], iter[MAXN];

void add_edge(int from, int to, int cap)
{
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}

void bfs(int s)
{
    memset(level, -1, sizeof(level)); queue<int> q;
    level[s] = 0; q.push(s);
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
    while (true) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f; while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < N; i++) scanf("%d%d", &A[i], &B[i]);
        for (int i = 0; i < M; i++) {
            scanf("%d%d%d", &P[i].first, &P[i].second, &W[i]);
            P[i].first -= 1; P[i].second -= 1;
        }

        for (int i = 0; i < N; i++) G[i].clear();
        memset(iter, 0, sizeof(iter));

        int s = N; int t = s + 1;
        for (int i = 0; i < N; i++) add_edge(i, t, A[i]), add_edge(s, i, B[i]);
        for (int i = 0; i < M; i++) {
            add_edge(P[i].first, P[i].second, W[i]);
            add_edge(P[i].second, P[i].first, W[i]);
        }
        printf("%d\n", max_flow(s, t));
    }
}
