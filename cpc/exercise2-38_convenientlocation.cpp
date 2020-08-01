// AOJ 0189
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const int MAXN = 10+10;
int G[MAXN][MAXN];
int N, M;

void print_2darray(int a[MAXN][MAXN], int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) printf("%d%c", a[i][j], j==c-1?'\n':' ');
}


void solve()
{
    for (int i = 0; i < N; i++) G[i][i] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (G[i][k] + G[k][j] < G[i][j]) G[i][j] = G[i][k] + G[k][j];
            }
        }
    }
    // print_2darray(G, N, N); printf("\n");
    int besti = 0, bestsum = INF;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) sum += G[i][j];
        if (sum < bestsum) { besti = i; bestsum = sum; }
    }
    printf("%d %d\n", besti, bestsum);
}

int main()
{
    while (scanf("%d", &M) == 1 && M) {
        memset(G, 0x3f, sizeof(G));
        N = 0;
        for (int i = 0; i < M; i++) {
            int f, t, c; scanf("%d%d%d", &f, &t, &c);
            G[f][t] = G[t][f] = c;
            N = max(N, max(f, t));
        }
        N++;
        solve();
    }
}
