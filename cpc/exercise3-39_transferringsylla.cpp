// POJ 3713 Transferring Sylla
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

struct Edge {
    int to, cap, rev;
    Edge(int t=0, int c=0, int r=0) { to=t; cap=c; rev=r; }
};

const int MAXN = 500+5;
const int INF = 100000;
const int MAXM = 20000+5;
PII E[MAXM];
vector<Edge> G[MAXN];
bool used[MAXN];
int N, M;

void add_edge(int from, int to, int cap)
{
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}

int dfs(int v, int t, int f)
{
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        Edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
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
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        else flow += f;
    }
}

void init_edge()
{
    for (int i = 0; i < N; i++) G[i].clear();
    for (int i = 0; i < M; i++) {
        int a = E[i].first, b = E[i].second;
        add_edge(a, b, 1); add_edge(b, a, 1);
    }
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;
        // printf("N, M = %d %d\n", N, M);
        for (int i = 0; i < M; i++) scanf("%d%d", &E[i].first, &E[i].second);

        bool yes = true;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (i == j) continue;
                init_edge();
                int flow = max_flow(i, j);
                // printf("%d-%d %d\n", i, j, flow);
                if (flow < 3) { yes = false; break; }
            }
        }

        if (yes) printf("YES\n");
        else printf("NO\n");
    }
}
