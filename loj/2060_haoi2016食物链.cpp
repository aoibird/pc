// LOJ 2060 「HAOI2016」食物链
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

const int MAXN = 1e5+5;
int N, M;
vector<int> G[MAXN];
bool root[MAXN];
int dp[MAXN];

int dfs(int s)
{
    if (dp[s] != 0) return dp[s];
    if (G[s].size() == 0) return 1;

    int sum = 0;
    for (int i = 0; i < G[s].size(); i++) sum += dfs(G[s][i]);
    return dp[s] = sum;
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) { G[i].clear(); root[i] = true; }
        for (int i = 0; i < M; i++) {
            int a, b; scanf("%d%d", &a, &b); a--; b--;
            G[b].push_back(a); root[a] = false;
        }

        for (int i = 0; i < N; i++) dfs(i);

        int sum = 0;
        for (int i = 0; i < N; i++) if (root[i]) sum += dp[i];
        printf("%d\n", sum);
        // for (int i = 0; i < N; i++) printf("%d%c", dp[i], i+1==N?'\n':' ');
        // for (int i = 0; i < N; i++) printf("%d%c", root[i], i+1==N?'\n':' ');
    }
}
