// AOJ 2249
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
    int to, len, cost;
    Edge(int t=0, int l=0, int c=0) { to=t; len=l; cost=c; }
};

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
vector<Edge> G[MAXN];
int D[MAXN];
int F[MAXN];
int C[MAXN];
int N, M;

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}

void print_vector(vector<Edge> v)
{
    for (int i = 0; i < v.size(); i++)
        printf("(%d,%d,%d)%c", v[i].to, v[i].len, v[i].cost, i==v.size()-1?'\n':' ');
}


void solve()
{
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    fill(D, D+N+1, INF);
    fill(C, C+N+1, INF);
    fill(F, F+N+1, INF);
    D[1] = 0; C[1] = 0;
    pq.push(PII(D[1], 1));
    while (!pq.empty()) {
        PII p = pq.top(); pq.pop();
        int v = p.second;
        if (D[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            Edge e = G[v][i]; int u = e.to, len = e.len, cost = e.cost;
            if (D[u] > D[v] + len || (D[u]==D[v]+len && F[v] > cost)) {
                D[u] = D[v] + len; C[u] = C[v] + cost; F[u] = cost;
                pq.push(PII(D[u], u));
            }
        }
    }
    // printf("D: "); print_array(D, N+1);
    // printf("C: "); print_array(C, N+1);
    // printf("F: "); print_array(F, N+1);
    // printf("\n");
    int sum = 0;
    for (int i = 2; i <= N; i++) sum += F[i];
    printf("%d\n", sum);
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;
        for (int i = 1; i <= N; i++) G[i].resize(0);
        for (int i = 0; i < M; i++) {
            int f, t, l, c; scanf("%d%d%d%d", &f, &t, &l, &c);
            G[f].push_back(Edge(t, l, c));
            G[t].push_back(Edge(f, l, c));
        }

        solve();
    }
}
