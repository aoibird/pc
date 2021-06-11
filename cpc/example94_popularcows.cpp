// POJ 2186 Popular Cows
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

const int MAXN = 10000+5;
// const int MAXM = 50000+5;
vector<int> G[MAXN];
vector<int> GR[MAXN];
bool VIS[MAXN];
int COMPO[MAXN];
vector<int> SEQ;
int N, M;


void dfs(int x)
{
    VIS[x] = true;
    for (int i = 0; i < G[x].size(); i++) {
        int u = G[x][i];
        if (!VIS[u]) dfs(u);
    }
    SEQ.push_back(x);
}

void rdfs(int x, int nc)
{
    VIS[x] = true;
    COMPO[x] = nc;
    for (int i = 0; i < GR[x].size(); i++) {
        int u = GR[x][i];
        if (!VIS[u]) rdfs(u, nc);
    }
}

int scc()
{
    memset(COMPO, 0, sizeof(COMPO));
    SEQ.clear();

    memset(VIS, 0, sizeof(VIS));
    for (int i = 1; i <= N; i++) {
        if (!VIS[i]) dfs(i);
    }

    memset(VIS, 0, sizeof(VIS));
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!VIS[i]) rdfs(i, cnt++);
    }

    return cnt;
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 1; i <= N; i++) { G[i].clear(); GR[i].clear(); }
        for (int i = 0; i < M; i++) {
            int a, b; scanf("%d%d", &a, &b);
            G[a].push_back(b); GR[b].push_back(a);
        }

        int nscc = scc();

        int last = 0, n = 0;
        for (int i = 1; i <= N; i++) {
            if (COMPO[i] == nscc - 1) { last = i; n++; }
        }
        memset(VIS, 0, sizeof(VIS));
        rdfs(last, 0);
        for (int i = 1; i <= N; i++) {
            if (!VIS[i]) { n = 0; break; }
        }

        printf("%d\n", n);
    }
}
