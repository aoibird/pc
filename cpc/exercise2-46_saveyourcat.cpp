// AOJ 2224
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
    int from, to; double cost;
    Edge(int f=0, int t=0, double c=0) { from=f; to=t; cost=c; }
};

const int MAXN = 1e5 + 10;
PII piles[MAXN];
vector<Edge> G;
double S;
int N, M;

int par[MAXN];

void init(int n)
{
    for (int i = 1; i <= N; i++) par[i] = i;
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

double get_dist(int x1, int y1, int x2, int y2)
{
    return sqrt(1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2));
}

bool cmp(const Edge &a, const Edge &b) { return a.cost > b.cost; }

void solve()
{
    sort(G.begin(), G.end(), cmp);
    double sum = 0;
    for (int i = 0; i < G.size(); i++) {
        int f = G[i].from, t = G[i].to; double c = G[i].cost;
        if (find(f) == find(t)) continue;
        sum += c;
        unite(f, t);
    }
    printf("%.3lf\n", S-sum);
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        init(N); G.resize(0); S = 0;
        for (int i = 1; i <= N; i++) {
            int x, y; scanf("%d%d", &x, &y);
            piles[i] = PII(x, y);
        }
        for (int i = 0; i < M; i++) {
            int f, t; scanf("%d%d", &f, &t);
            double c = get_dist(piles[f].first, piles[f].second,
                                piles[t].first, piles[t].second);
            G.push_back(Edge(f, t, c));
            S += c;
        }

        solve();
    }
}
