#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10000+10;
int X[MAXN];
int Y[MAXN];
bool G[MAXN][MAXN];
bool V[MAXN];
int M[MAXN];
int n, m, e;

void input()
{
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 0; i < e; i++) {
        int f, t; scanf("%d%d", &f, &t);
        G[f][t] = true;
    }
}

bool dfs(int x)
{
    for (int i = 0; i < m; i++) {
        if (G[x][i] && !V[i]) {
            V[i] = true;
            if (!M[i] || dfs(M[i])) {
                M[i] = x;
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        memset(V, 0, sizeof(V));
        if (dfs(i)) sum++;
    }
    printf("%d\n", sum);
}

int main()
{
    input();
    solve();
}
