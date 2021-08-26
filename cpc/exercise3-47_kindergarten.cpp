// POJ 3692 Kindergraten
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

const int MAXV = 200+200+5;
int G, B, M;
int R[MAXV][MAXV];
vector<int> GR[MAXV];
int match[MAXV];
bool used[MAXV];

void add_edge(int u, int v) { GR[u].push_back(v); GR[v].push_back(u); }

bool dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < GR[v].size(); i++) {
        int u = GR[v][i]; int w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) {
            match[v] = u; match[u] = v; return true;
        }
    }
    return false;
}

int matching()
{
    memset(match, -1, sizeof(match));
    int res = 0;
    int V = G + B;
    for (int v = 0; v < V; v++) {
        if (match[v] < 0) { memset(used, 0 ,sizeof(used)); res += dfs(v); }
    }
    return res;
}

int main()
{
    int tc = 1;
    while (scanf("%d%d%d", &G, &B, &M) == 3 && G && B) {
        memset(R, 0, sizeof(R));
        for (int i = 0; i < G+B; i++) GR[i].clear();
        for (int i = 0; i < M; i++) {
            int g, b; scanf("%d%d", &g, &b); g--; b--;
            R[g][b+G] = 1;
        }
        for (int i = 0; i < G; i++)
            for (int j = 0; j < G; j++) R[i][j] = 1;
        for (int i = G; i < G+B; i++)
            for (int j = G; j < G+B; j++) R[i][j] = 1;

        for (int i = 0; i < G; i++)
            for (int j = G; j < G+B; j++) if (R[i][j] == 0) add_edge(i, j);

        // [0, G-1] girls, [G, G+B-1] boys
        int m = matching();
        printf("Case %d: %d\n", tc, G+B-m);
        tc++;
    }
}
