// POJ 3041 Asteroids
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

const int MAXN = 500+5;
const int MAXK = 1e4+5;
int R[MAXK], C[MAXK];
int N, K;

const int MAXV = MAXN*2;
int V;
vector<int> G[MAXV];
int match[MAXV];
bool used[MAXV];

void add_edge(int u, int v) { G[u].push_back(v); G[v].push_back(u); }

bool dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) { match[v] = u, match[u] = v; return true; }
    }
    return false;
}

int bipartite_matching()
{
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; v++) {
        if (match[v] < 0) { memset(used, 0, sizeof(used)); cnt += dfs(v); }
    }
    return cnt;
}


int main()
{
    while (scanf("%d%d", &N, &K) == 2 && N) {
        for (int i = 0; i < K; i++) scanf("%d%d", &R[i], &C[i]);

        V = N*2;
        for (int i = 0; i < V; i++) G[i].clear();
        for (int i = 0; i < K; i++) add_edge(R[i]-1, N+C[i]-1);
        printf("%d\n", bipartite_matching());
    }
}
