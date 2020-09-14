// POJ 2112 Optimal Milking
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

const int INF = 0x3f3f3f3f;
const int MAXKC = 30+200+5;
int K, C, M;
int D[MAXKC][MAXKC];

struct Edge {
    int to, cap, rev;
    Edge(int t=0, int c=0, int r=0) { to=t; cap=c; rev=r; }
};
const int MAXV = MAXKC+10;
vector<Edge> G[MAXV];
int level[MAXV], iter[MAXV];

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
                level[e.to] = level[v] + 1;
                q.push(e.to);
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

bool can(int mid)
{
    // s -> [K+1, K+C] cows -> [1, K] machines -> t
    for (int i = 0; i < MAXV; i++) G[i].clear();

    int s = 0, t = K+C+1;
    for (int i = 1; i <= K; i++) { add_edge(i, t, M); }
    for (int i = K+1; i <= K+C; i++) { add_edge(s, i, 1); }
    for (int i = K+1; i <= K+C; i++) {
        for (int j = 1; j <= K; j++) {
            if (i != j && D[i][j] <= mid) { add_edge(i, j, 1); }
        }
    }

    int flow = max_flow(s, t);
    return flow == C;
}

void solve()
{
    for (int k = 1; k <= K+C; k++) {
        for (int i = 1; i <= K+C; i++) {
            for (int j = 1; j <= K+C; j++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }

    // for (int i = 1; i <= K+C; i++) {
    //     for (int j = 1; j <= K+C; j++) printf("%d%c", D[i][j], j==K+C?'\n':' ');
    // }

    int lb = 0, ub = INF;
    while (ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if (can(mid)) { ub = mid; }
        else { lb = mid; }
    }
    printf("%d\n", ub);
}

int main()
{
    while (scanf("%d%d%d", &K, &C, &M) == 3) {
        for (int i = 1; i <= K+C; i++) {
            for (int j = 1; j <= K+C; j++) {
                int a; scanf("%d", &a);
                if (i != j && a == 0) D[i][j] = INF;
                else D[i][j] = a;
            }
        }

        solve();
    }
}
