// POJ 3713 Transferring Sylla
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

struct Edge {
    int to, cap, bak, rev;
    Edge(int t=0, int c=0, int r=0) { to=t; bak=cap=c; rev=r; }
};

const int MAXN = 500+5;
const int INF = 100000;
const int MAXM = 20000+5;
PII E[MAXM];
vector<Edge> G[MAXN*2];
int level[MAXN*2], iter[MAXN*2];
int N, M;

void add_edge(int from, int to, int cap)
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
    while (flow < 3) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f; while (flow < 3 && (f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
}

void init_edge()
{
    for (int i = 0; i < N; i++) { add_edge(i, i+N, 1); }
    for (int i = 0; i < M; i++) {
        int a = E[i].first, b = E[i].second;
        int a2 = a + N, b2 = b + N;
        add_edge(b2, a, 1); add_edge(a2, b, 1);
    }

}

void recover_edge()
{
    for (int i = 0; i < N*2; i++) {
        for (int j = 0; j < G[i].size(); j++) G[i][j].cap = G[i][j].bak;
    }
}

void init_graph() { for (int i = 0; i < N*2; i++) G[i].clear(); }

void print_graph()
{
    for (int i = 0; i < N*2; i++) {
        printf("%d: ", i);
        for (int j = 0; j < G[i].size(); j++) printf(" (%d %d)", G[i][j].to, G[i][j].cap);
        printf("\n");
    }
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;
        // printf("N, M = %d %d\n", N, M);
        for (int i = 0; i < M; i++) scanf("%d%d", &E[i].first, &E[i].second);

        // init_graph(), init_edge();
        // print_graph();

        init_graph(); init_edge();
        bool yes = true;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (i == j) continue;
                recover_edge();
                int flow = max_flow(i+N, j);
                // printf("%d-%d %d\n", i, j, flow);
                if (flow < 3) { yes = false; break; }
            }
            if (yes == false) break;
        }

        if (yes) printf("YES\n");
        else printf("NO\n");
    }
}
