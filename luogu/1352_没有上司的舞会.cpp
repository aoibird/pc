// Luogu 1352 没有上司的舞会
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

const int MAXN = 1000+10;
vector<int> children[MAXN];
int happy[MAXN];
int par[MAXN];
int dp[MAXN][2];
int N;

int dfs(int x, bool join)
{
    if (children[x].size() == 0) { return dp[x][join] = (join)? happy[x] : 0; }
    if (dp[x][join] != -1) return dp[x][join];

    int sum = join ? happy[x] : 0;
    for (int i = 0; i < children[x].size(); i++) {
        int child = children[x][i];
        if (join) sum += dfs(child, !join);
        else sum += max(dfs(child, true), dfs(child, false));
    }
    return dp[x][join] = sum;
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 1; i <= N; i++) children[i].clear();
        for (int i = 1; i <= N; i++) par[i] = i;
        memset(dp, -1, sizeof(dp));

        for (int i = 1; i <= N; i++) scanf("%d", &happy[i]);
        for (int i = 0; i < N-1; i++) {
            int l, k; scanf("%d%d", &l, &k);
            par[l] = k; children[k].push_back(l);
        }
        int boss = 1;
        for (int i = 1; i <= N; i++) if (par[i] == i) { boss = i; break; }

        int sum = max(dfs(boss, true), dfs(boss, false));
        printf("%d\n", sum);
    }
}
