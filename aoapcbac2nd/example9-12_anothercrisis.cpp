// UVa 12186
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100000+10;
vector<int> children[MAXN];
int N, T;

int dfs(int u)
{
    if (children[u].empty()) return 1;

    int k = children[u].size();
    vector<int> dp;
    for (int i = 0; i < k; i++) {
        dp.push_back(dfs(children[u][i]));
    }
    sort(dp.begin(), dp.end());
    int c = (k*T - 1)/100 + 1;
    int ans = 0;
    for (int i = 0; i < c; i++) ans += dp[i];
    return ans;
}

int main()
{
    while (scanf("%d%d", &N, &T) == 2 && N && T) {
        for (int i = 0; i <= N; i++) children[i].clear();
        for (int i = 1; i <= N; i++) {
            int par; scanf("%d", &par);
            children[par].push_back(i);
        }

        int res = dfs(0);
        printf("%d\n", res);
    }
}
