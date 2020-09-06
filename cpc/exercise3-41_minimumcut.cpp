// POJ 2914 Minimum Cut
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 500+5; // [2, 500]
// const int MAXM = MAXN * (MAXN - 1) /2; // [0, N*(N-1)/2]
int N, M;
int G[MAXN][MAXN];
vector<int> V;
int W[MAXN];
bool vis[MAXN];

void print_graph()
{
    printf("G:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) printf("%d%c", G[i][j], j+1==N?'\n':' ');
}

void print_vector(char c, vector<int> V)
{
    printf("%c: ", c);
    for (int i = 0; i < V.size(); i++) printf("%d%c", V[i], i+1==V.size()?'\n':' ');
}


int phrase(int a)
{
    memset(W, 0, sizeof(W));
    memset(vis, 0, sizeof(vis));
    vector<int> A; A.push_back(a); vis[a] = true;
    while (A.size() < V.size()) {
        int maxw = 0, maxu;
        for (int i = 0; i < V.size(); i++) {
            int u = V[i];
            if (vis[u]) continue;
            W[u] += G[A.back()][u];
            if (W[u] > maxw) { maxw = W[u]; maxu = u; }
        }
        if (maxw == 0) return 0;
        A.push_back(maxu); vis[maxu] = true;
    }
    int y = A.back(); A.pop_back();
    int x = A.back();
    for (vector<int>::iterator it=V.begin(); it != V.end(); it++)
        if (*it == y) { V.erase(it); break; }
    for (int j = 0; j < N; j++) {
        G[x][j] += G[y][j]; G[j][x] = G[x][j];
        G[y][j] = G[j][y] = 0;
    }
    return W[y];
}

int min_cut()
{
    int cut = INT_MAX;
    while (V.size() > 1) {
        int c = phrase(V.back());
        if (c == 0) return 0;
        cut = min(cut, c);
    }
    return cut;
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        // printf("N, M == %d %d\n", N, M);
        memset(G, 0, sizeof(G));
        V.clear();
        for (int i = 0; i < M; i++) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            G[a][b] += c; G[b][a] += c;
        }
        for (int i = 0; i < N; i++) V.push_back(i);

        printf("%d\n", min_cut());
    }
}
