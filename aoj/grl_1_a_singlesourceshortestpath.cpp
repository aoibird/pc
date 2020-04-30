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
typedef pair<int,ll> PILL;
struct Edge {
    int to;
    ll dist;
    Edge(int t=0, ll d=0) { to = t; dist = d; }
};

const int MAXN = 100000+10;
const ll INF = 1LL << 62;
vector<Edge> G[MAXN];
int n, m, r;
ll D[MAXN];

void input()
{
    scanf("%d%d%d", &n, &m, &r);
    for (int i = 0; i < m; i++) {
        int f, t; ll d; scanf("%d%d%lld", &f, &t, &d);
        G[f].push_back(Edge(t, d));
    }
}

void solve()
{
    priority_queue<PILL, vector<PILL>, greater<PILL> > pq;
    for (int i = 0; i < n; i++) D[i] = INF;
    D[r] = 0;
    pq.push(PILL(D[r], r));

    while (!pq.empty()) {
        PILL p = pq.top(); pq.pop();
        ll d = p.first; int v = p.second;
        if (D[v] < d) continue;

        for (int i = 0; i < G[v].size(); i++) {
            int to = G[v][i].to; ll dist = G[v][i].dist;
            if (D[v] + dist < D[to]) {
                D[to] = D[v] + dist;
                pq.push(PILL(D[to], to));
            }
        }
    }
}

int main()
{
    input();
    solve();
    for (int i = 0; i < n; i++) {
        if (D[i] != INF)printf("%lld\n", D[i]);
        else printf("INF\n");
    }
}
