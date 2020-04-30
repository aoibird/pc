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

typedef pair<int,int> PII;
struct Edge {
    int to, dist;
    Edge(int t=0, int d=0) { to = t; dist = d; }
};

const int MAXN = 100000+10;
const int INF = 200000000;
vector<Edge> G[MAXN];
int n, m, r;
int D[MAXN];

void input()
{
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        int f, t, d; scanf("%d%d%d", &f, &t, &d);
        G[f].push_back(Edge(t, d));
    }
}

void solve()
{
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    for (int i = 0; i < n; i++) D[i] = INF;
    D[r] = 0;
    pq.push(PII(D[r], r));

    while (!pq.empty()) {
        PII p = pq.top(); pq.pop();
        int d = p.first, v = p.second;
        if (D[v] < d) continue;

        for (int i = 0; i < G[v].size(); i++) {
            int to = G[v][i].to, dist = G[v][i].dist;
            if (D[v] + dist < D[to]) {
                D[to] = D[v] + dist;
                pq.push(PII(D[to], to));
            }
        }
    }
}

int main()
{
    input();
    solve();
    for (int i = 0; i < n; i++) {
        if (D[i] != INF)printf("%d\n", D[i]);
        else printf("INF\n");
    }
}
