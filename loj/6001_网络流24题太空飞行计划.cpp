// LOJ 6001 「网络流 24 题」太空飞行计划
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXM = 50+10;
const int MAXN = MAXM;
const int INF = 1e9;

struct Edge {
    int to, cap, rev;
    Edge(int t=0, int c=0, int r=0) {
        to = t, cap = c, rev = r;
    }
};

vector<Edge> G[MAXN*2];
bool VIS[MAXN*2];
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
    scanf("%d%d", &M, &N);
    int S = 0, T = M+N+1;
    int sum = 0;
    for (int i = 1; i <= M; i++) {
        int p; scanf("%d", &p); sum += p;
        add_edge(S, i, p);
        int ch;
        while ((ch = getchar()) != '\n') {
            ungetc(ch, stdin);
            int j; scanf("%d", &j);
            add_edge(i, M + j, INF);
        }
    }

    for (int j = 1; j <= N; j++) {
        int c; scanf("%d", &c);
        add_edge(M + j, T, c);
    }

    int prof = sum - max_flow(S, T);
    vector<int> es, is;
    for (int i = 1; i <= M+N; i++) {
        if (VIS[i]) (i <= M) ? (es.push_back(i)) : (is.push_back(i-M));
    }
    for (unsigned int i = 0; i < es.size(); i++) printf("%d%c", es[i], i+1==es.size()?'\n':' ');
    for (unsigned int i = 0; i < is.size(); i++) printf("%d%c", is[i], i+1==is.size()?'\n':' ');
    printf("%d\n", prof);
}
