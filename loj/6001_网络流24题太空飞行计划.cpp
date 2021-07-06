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
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

const int MAXM = 50 + 2;
const int MAXN = MAXM;
const int MAXV = MAXM + MAXN + 2;
const int INF = 1e9;

struct Edge {
    int to;
    ll cap;
    int rev;
    Edge(int t = 0, ll c = 0, int r = 0) {
        to = t, cap = c, rev = r;
    }
};

vector<Edge> G[MAXV];
int V, N, M, S, T;

int level[MAXV], iter[MAXV];
void add_edge(int from, int to, ll cap) {
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size() - 1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (unsigned int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];

            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

ll dfs(int v, int t, ll f) {
    if (v == t)
        return f;

    for (int &i = iter[v]; i < (int) G[v].size(); i++) {
        Edge &e = G[v][i];

        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));

            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

ll max_flow(int s, int t) {
    ll flow = 0;

    while (true) {
        bfs(s);

        if (level[t] < 0)
            return flow;

        memset(iter, 0, sizeof(iter));
        ll f;

        while ((f = dfs(s, t, INF)) > 0)
            flow += f;
    }
}

bool vis[MAXV];
void access(int s) {
    vis[s] = true;

    for (unsigned int i = 0; i < G[s].size(); i++)
        if (!vis[G[s][i].to] && G[s][i].cap > 0)
            access(G[s][i].to);
}


int main() {
    scanf("%d%d", &M, &N);
    int S = 0, T = M + N + 1;
    ll sum = 0;

    for (int i = 1; i <= M; i++) {
        int p;
        scanf("%d", &p);
        sum += p;
        add_edge(S, i, p);
        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF) {
            ungetc(ch, stdin);
            int j;
            scanf("%d", &j);
            add_edge(i, M + j, INF);
        }
    }

    for (int j = 1; j <= N; j++) {
        int c;
        scanf("%d", &c);
        add_edge(M + j, T, c);
    }

    ll prof = sum - max_flow(S, T);
    memset(vis, 0, sizeof(vis));
    access(S);
    bool first = true;

    for (int i = 1; i <= M; i++) {
        if (!vis[i])
            continue;

        first ? first = false : printf(" ");
        printf("%d", i);
    }

    printf("\n");
    first = true;

    for (int i = M + 1; i <= M + N; i++) {
        if (!vis[i])
            continue;

        first ? first = false : printf(" ");
        printf("%d", i - M);
    }

    printf("\n");

    printf("%lld\n", prof);
}
