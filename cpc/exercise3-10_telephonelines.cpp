// POJ 3662
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

const int MAXN = 1000+5;
const int MAXL = 1000000+5;
int N, P, K;
vector<PII> G[MAXN];

bool vis[MAXN];
int fcntl, fcntg;

int dfs(int v, int t, int lim, int cntl, int cntg)
{
    if (v == t) { fcntl = cntl, fcntg = cntg; return true; }
    vis[v] = true;

    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i].first, dist = G[v][i].second;
        if (!vis[u]
            && (dist <= lim || (dist > lim && cntg+1 <= K))
            && dfs(u, t, lim, cntl+(dist<=lim), cntg+(dist>lim))) {
            vis[v] = false;
            return true;
        }
    }
    vis[v] = false;
    return false;
}


int main()
{
    while (scanf("%d%d%d", &N, &P, &K) == 3) {
        // printf("N, P, K = %d %d %d\n", N, P, K);
        for (int i = 0; i < MAXN; i++) G[i].clear();
        for (int i = 0; i < P; i++) {
            int a, b, l; scanf("%d%d%d", &a, &b, &l);
            G[a].push_back(PII(b, l));
            G[b].push_back(PII(a, l));
        }

        int lb = 0, ub = MAXL;
        while (ub - lb > 1) {
            int mid = (ub + lb) / 2;
            // printf("[%d %d %d] -> ", lb, mid, ub);
            memset(vis, 0, sizeof(vis));
            if (dfs(1, N, mid, 0, 0)) ub = mid;
            else lb = mid;
            // printf("[%d %d]\n", lb, ub);
        }

        // printf("[%d %d] fcntl = %d fcntg = %d K = %d\n", lb, ub, fcntl, fcntg, K);
        if (ub >= MAXL) printf("-1\n");
        else {
            if (fcntg < K) printf("0\n");
            else printf("%d\n", ub);
        }
    }
}
