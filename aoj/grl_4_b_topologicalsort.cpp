#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> PII;

const int MAXN = 10000+10;
vector<int> G[MAXN]; // index
int deg[MAXN];
queue<int> q; // index
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int f, t; scanf("%d%d", &f, &t);
        G[f].push_back(t);
        deg[t] += 1;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int from = q.front(); q.pop();
        printf("%d\n", from);
        for (int i = 0; i < G[from].size(); i++) {
            int to = G[from][i];
            deg[to] -= 1;
            if (deg[to] == 0) q.push(to);
        }
    }
}
