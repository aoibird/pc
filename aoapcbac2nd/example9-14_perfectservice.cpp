// UBa 1218
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
vector<int> children[MAXN];
int dp[MAXN][3];

void build_tree(int x)
{
    for (int i = 1; i <= N; i++) {
        if (G[x][i] == 1) {
            par[i] = x;
            children[x].push_back(i);
            G[x][i] = G[i][x] = 0;
            build_tree(i);
        }
    }
}

int dfs(int u, int c)
{
    if (dp[u][c] < INF) return dp[u][c];

    int nchild = children[u].size();

    int sum = 0;
    for (int i = 0; i < nchild; i++) {
        int v = children[u][i];
        if (c == 0) sum += min(dfs(v, 0), dfs(v, 1));
        else if (c == 1) sum += dfs(v, 2);
        else if (c == 2) dp[u][c] = min(dp[u][c], dfs(u, 1) - dfs(v, 2) + dfs(v, 0));
        else ;
    }
    if (c == 0) dp[u][c] = sum + 1;
    else if (c == 1) dp[u][c] = sum;
    else ;

    return dp[u][c];
}

void solve()
{
    par[1] = 1; build_tree(1);
    // for (int i = 1; i <= N; i++) printf("%d%c", par[i], i==N?'\n':' ');

    for (int i=0; i<N; i++) for (int c=0; c<3; c++) dp[i][c] = INF;
    int v1 = dfs(1, 0);
    int v2 = dfs(1, 2);
    if (v1 > 0 && v2 > 0) printf("%d\n", min(v1, v2));
    else if (v1 <= 0) printf("%d\n", v2);
    else if (v2 <= 0) printf("%d\n", v1);
    else printf("%d\n", 1);
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
        for (int i = 0; i < N; i++) children[i].clear();

        int e; scanf("%d", &e);
        if (e == -1) break;
    }
}
