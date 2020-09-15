// POJ 2226 Muddy Fields
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

const int MAXRC = 50+5;
int R, C;
int B;
char F[MAXRC][MAXRC];

const int MAXV = MAXRC*MAXRC*2;
vector<int> G[MAXV];
int match[MAXV];
bool used[MAXV];
PII pairs[MAXRC][MAXRC];

void add_edge(int u, int v) { G[u].push_back(v); G[v].push_back(u); }

bool dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) { match[v] = u; match[u] = v; return true; }
    }
    return false;
}

int matching()
{
    memset(match, -1, sizeof(match));
    int V = B;
    int res = 0;
    for (int v = 0; v < V; v++) {
        if (match[v] < 0) { memset(used, 0, sizeof(used)); res += dfs(v); }
    }
    return res;
}

void solve()
{
    B = 0;
    // [0, R*C-1] fields, [R*C, R*C+B-1] wooden boards
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) pairs[i][j] = PII(-1, -1);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (F[i][j] != '*') continue;
            if (j - 1 < 0 || F[i][j-1] != '*') B++;
            pairs[i][j].first = B-1;
        }
    }
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < R; i++) {
            if (F[i][j] != '*') continue;
            if (i - 1 < 0 || F[i-1][j] != '*') B++;
            pairs[i][j].second = B-1;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i >= 0 && j >= 0) add_edge(pairs[i][j].first, pairs[i][j].second);
        }
    }

    int m = matching();
    printf("%d\n", m);
}

int main()
{
    while (scanf("%d%d", &R, &C) == 2 && R && C) {
        for (int i = 0; i < R*C*2; i++) G[i].clear();

        int ch; while ((ch = getchar()) != EOF && ch != '\n') ;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) { F[i][j] = getchar(); }
            getchar();
        }

        solve();
    }
}
