// POJ 1466 Girls and Boys
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

const int MAXN = 500+10;
int N;
vector<int> G[MAXN];

int match[MAXN];
bool used[MAXN];

// void add_edge(int u, int v)
// {
//     G[u].push_back(v); G[v].push_back(u);
// }

bool dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) { match[u] = v; match[v] = u; return true; }
    }
    return false;
}

int matching()
{
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < N; v++) {
        if (match[v] < 0) { memset(used, 0, sizeof(used)); res += dfs(v); }
    }
    return res;
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) G[i].clear();
        for (int i = 0; i < N; i++) {
            int ch, v, x, u; scanf("%d", &v);
            while ((ch = getchar()) != '(') ;
            scanf("%d", &x); getchar();
            for (int j = 0; j < x; j++) { scanf("%d", &u); G[v].push_back(u); }
        }

        // for (int v = 0; v < N; v++) {
        //     printf("%d: ", v);
        //     for (int j = 0; j < G[v].size(); j++) printf("%d ", G[v][j]);
        //     printf("\n");
        // }
        int m = matching();
        printf("%d\n", N-m);

    }
}
