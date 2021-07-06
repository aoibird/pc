// LOJ 6000 「网络流 24 题」搭配飞行员
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
    int to;
    int cap;
    int rev;

    Edge(int t=0, int c=0, int r=0) {
        to = t, cap = c, rev = r;
    }
};

const int MAXN = 100+10;
const int INF = MAXN*2;
vector<Edge> G[MAXN];
bool VIS[MAXN];
int N, M, S, T;

void add_edge(int from, int to, int cap)
{
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size()-1));
}

int dfs(int v, int t, int f)
{
    if (v == t) return f;
    VIS[v] = true;
    for (unsigned int i = 0; i < G[v].size(); i++) {
        Edge &e = G[v][i];
        if (!VIS[e.to] && e.cap > 0) {
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
        memset(VIS, 0, sizeof(VIS));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N; i++) G[i].clear();
    memset(VIS, 0, sizeof(VIS));

    int a, b;
    while (scanf("%d%d", &a, &b) == 2) {
        add_edge(a, b, 1);
    }

    S = 0, T = N+1;
    for (int i = 1; i <= M; i++) { add_edge(S, i, 1); }
    for (int i = M+1; i <= N; i++) { add_edge(i, T, 1); }

    int flow = max_flow(S, T);
    printf("%d\n", flow);
}
