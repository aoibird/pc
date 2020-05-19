// UVa 1218
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

const int MAXN = 10000+10;
const int INF = 100000000;
int G[MAXN][MAXN];
int N;
int par[MAXN];
vector<int> vert, children[MAXN];
int dp[MAXN][3];

void build_tree(int x)
{
    vert.push_back(x);
    for (int i = 1; i <= N; i++) {
        if (G[x][i] == 1) {
            G[x][i] = G[i][x] = 0;
            par[i] = x;
            children[x].push_back(i);
            build_tree(i);
        }
    }
}

void print_table()
{
    printf("par & vert:\n");
    for (int i = 1; i <= N; i++) printf("%d%c", par[i], i==N?'\n':' ');
    for (int i = 0; i < vert.size(); i++) printf("%d ", vert[i]); printf("\n");
}

void solve()
{
    par[1] = 1; build_tree(1);
    // print_table();

    for (int i = vert.size()-1; i >= 0; i--) {
        int u = vert[i];
        dp[u][0] = 1; dp[u][1] = 0;
        for (int j = 0; j < children[u].size(); j++) {
            int v = children[u][j];
            dp[u][0] += min(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][2];
            dp[u][0] = min(dp[u][0], INF);
            dp[u][1] = min(dp[u][1], INF);
        }
        dp[u][2] = INF;
        for (int j = 0; j < children[u].size(); j++) {
            int v = children[u][j];
            dp[u][2] = min(dp[u][2], dp[u][1] - dp[v][2] + dp[v][0]);
        }
        // printf("%d: %d %d %d\n", u, dp[u][0], dp[u][1], dp[u][2]);
    }
    printf("%d\n", min(dp[1][0], dp[1][2]));
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N-1; i++) {
            int a, b; scanf("%d%d", &a, &b);
            G[a][b] = G[b][a] = 1;
        }

        solve();

        memset(G, 0, sizeof(G));
        memset(par, 0, sizeof(par));
        memset(dp, 0, sizeof(dp));
        vert.clear();
        for (int i = 1; i <= N; i++) children[i].clear();

        int e; scanf("%d", &e);
        if (e == -1) break;
    }
}
