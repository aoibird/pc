// LOJ 6003 「网络流 24 题」魔术球
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> PII;

const int MAXN = 55 + 5; // max number of paths
const int MAXS = 2000; // max number of nodes
int N, V;
vector<int> G[MAXS * 2 + 10];
int match[MAXS * 2 + 10];
bool used[MAXS * 2 + 10];

map<int,int> MAP;

void print_map()
{
    for (int i = 1; i < 12; i++) {
        for (int j = 1; j < i; j++) {
            if (MAP.count(j+i) > 0) { printf("%d -> %d\n", i, j); }
        }
    }
}

void print_vector(vector<int> &v)
{
    for (uint i = 0; i < v.size(); i++) printf("%d%c", v[i], i+1==v.size()?'\n':' ');
}

void add_edge(int u, int v) { G[u].push_back(v); G[v].push_back(u); }

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


vector<int> P[MAXS + 10];
vector<int> path;
void dft(vector<int> &path, int v)
{
    used[v] = true; path.push_back(v);
    for (uint i = 0; i < P[v].size(); i++) {
        int u = P[v][i];
        if (!used[u]) { dft(path, u); }
    }
}
void print(int n)
{
    for (int i = 0; i < n; i++) {
        if (match[i] == -1) continue;
        int v = i, u = match[v]-MAXS;
        P[v].push_back(u); P[u].push_back(v);
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        path.clear(); dft(path, i);
        for (uint i = 0; i < path.size(); i++) printf("%d%c", path[i] + 1, i+1==path.size()?'\n':' ');
    }
}

int solve()
{
    int best = 0;
    for (int i = 1; ; i++) {
        for (int j = 1; j < i; j++) {
            if (MAP.count(j+i) > 0) {
                add_edge(j - 1, i + MAXS - 1);
            }
        }
        V = i * 2;
        int res = bitpartite_matching();
        if (i-res <= N) best = max(best, i);
        else return best;
    }
    return best;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= MAXS; i++) { MAP[i*i] = i; }
    int res = solve();
    printf("%d\n", res);
    print(res);
}
