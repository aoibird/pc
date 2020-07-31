// POJ 2377
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
    int from, to, cost;
    Edge(int f=0, int t=0, int c=0) { from=f; to=t; cost=c; }
};

const int MAXN = 1000+10;
vector<Edge> G;
int N, M;

int par[MAXN];

void init(int n)
{
    for (int i = 1; i <= n; i++) par[i] = i;
}

int find(int x)
{
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x); y = find(y);
    if (x == y) return;
    else par[y] = x;
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


bool cmp(const Edge &a, const Edge &b) { return a.cost > b.cost; }

void solve()
{
    init(N);
    sort(G.begin(), G.end(), cmp);
    int sum = 0;
    for (int i = 0; i < G.size(); i++) {
        int from = G[i].from, to = G[i].to, cost = G[i].cost;
        if (find(from) == find(to)) continue;
        unite(from, to);
        sum += cost;
    }

    // print_array(par, N+1);
    int root = find(1);
    for (int i = 2; i <= N; i++) {
        if (find(i) != root) { printf("-1\n"); return; }
    }
    printf("%d\n", sum);
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        G.resize(0);
        for (int i = 0; i < M; i++) {
            int f, t, c; scanf("%d%d%d", &f, &t, &c);
            G.push_back(Edge(f, t, c));
        }

        solve();
    }
}
