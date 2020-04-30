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
struct Edge {
    int from, to; ll weight;
    Edge(int f=0, int t=0, ll w=0) { from=f; to=t; weight=w; }
};

const int MAXN = 100000+10;
vector<Edge> edges;
int n, m;
int par[MAXN];

int find(int x)
{
    if (x == par[x]) return x;
    else return par[x] = find(par[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[x] = y;
}

bool compare(const Edge & a, const Edge & b)
{
    return a.weight < b.weight;
}

void solve()
{
    ll sum = 0;
    sort(edges.begin(), edges.end(), compare);
    for (int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        int from = e.from; int to = e.to; ll weight = e.weight;
        if (find(from) != find(to)) {
            merge(from, to);
            sum += weight;
        }
    }
    printf("%lld\n", sum);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int f, t; ll w; scanf("%d%d%lld", &f, &t, &w);
        edges.push_back(Edge(f, t, w));
    }
    for (int i = 0; i < n; i++) par[i] = i;

    solve();
}
