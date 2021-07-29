// LOJ 6002 「网络流 24 题」最小路径覆盖
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
typedef unsigned int uint;
typedef pair<int,int> PII;

const int MAXN = 200 + 5;
const int MAXV = MAXN * 2 + 5;
int N, M, V;
vector<int> G[MAXV];
int match[MAXV];
bool used[MAXV];

vector<int> P[MAXN];
vector<int> path;

void add_edge(int u, int v)
{
    G[u].push_back(v); G[v].push_back(u);
}

bool dfs(int v)
{
    used[v] = true;
    for (uint i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) { match[v] = u; match[u] = v; return true; }
    }
    return false;
}

int bitpartite_matching()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; v++) {
        if (match[v] < 0) {
            memset(used, 0, sizeof(used));
            if (dfs(v)) { res++; }
        }
    }
    return res;
}

void dft(vector<int> &path, int v)
{
    used[v] = true; path.push_back(v);
    for (uint i = 0; i < P[v].size(); i++) {
        int u = P[v][i];
        if (!used[u]) { dft(path, u); }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        add_edge(a - 1, b + N - 1);
    }

    V = 2 * N;
    int res = bitpartite_matching();

    for (int i = 0; i < N; i++) {
        if (match[i] != -1) { P[i].push_back(match[i] - N); P[match[i]-N].push_back(i); }
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        path.clear(); dft(path, i);
        for (uint i = 0; i < path.size(); i++) printf("%d%c", path[i] + 1, i+1==path.size()?'\n':' ');
    }

    printf("%d\n", N-res);
}
