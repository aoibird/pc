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

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}

void print_vector(vector<int> v)
{
    for (uint i = 0; i < v.size(); i++) printf("%d%c", v[i], i+1==v.size()?'\n':' ');
}


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


int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        add_edge(a - 1, b + N - 1);
    }

    V = 2 * N;
    int res = bitpartite_matching();

    memset(used, 0, sizeof(used));
    for (int i = 0; i < N; i++) {
        if (used[i]) continue;
        int u = i; vector<int> p;
        p.push_back(u + 1);
        while (match[u] != -1) {
            p.push_back(match[u] - N + 1);
            used[u] = used[u-N] = true;
            u = match[u] - N;
        }
        used[u] = true;
        print_vector(p);
    }
    printf("%d\n", N-res);
}
