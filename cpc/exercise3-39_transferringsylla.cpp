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
vector<Edge> G[MAXN];
int level[MAXN], iter[MAXN];
bool indep[MAXN];
int N, M;

void print_graph()
{
    for (int i = 0; i < N; i++) {
        printf("%d: ", i);
        for (int j = 0; j < G[i].size(); j++) printf(" (%d %d)", G[i][j].to, G[i][j].cap);
        printf("\n");
    }
}

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
            if (e.cap>0 && level[e.to]<0 && !indep[e.to]) {
                level[e.to] = level[v]+1; q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
        Edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to] && !indep[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d; G[e.to][e.rev].cap += d;
                if (e.to != t) indep[e.to] = true;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    memset(indep, 0, sizeof(indep)); indep[s] = true;
    while (true) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f; while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
}


void recover_edge()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < G[i].size(); j++) G[i][j].cap = G[i][j].bak;
    }
}


int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;
        // printf("N, M = %d %d\n", N, M);
        for (int i = 0; i < N; i++) G[i].clear();
        for (int i = 0; i < M; i++) scanf("%d%d", &E[i].first, &E[i].second);

        for (int i = 0; i < M; i++) {
            add_edge(E[i].first, E[i].second, 1);
            add_edge(E[i].second, E[i].first, 1);
        }
        bool yes = true;
        for (int i = 0; i < N && yes; i++) {
            for (int j = i+1; j < N && yes; j++) {
                if (i == j) continue;
                recover_edge();
                int flow = max_flow(i, j);
                if (flow < 3) yes = false;
            }
        }

        if (yes) printf("YES\n");
        else printf("NO\n");
    }
}
