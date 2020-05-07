// UVa 11400
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Lamp {
    int V, K, C, L;
    Lamp(int iv=0, int ik=0, int ic=0, int il=0) { V=iv; K=ik; C=ic; L=il; }
};

const int INF = 1000000000;
const int MAXN = 1000+10;
Lamp A[MAXN];
int S[MAXN];
int N;
int dp[MAXN];

bool compare(const Lamp &a, const Lamp &b)
{
    return a.V < b.V;
}

void print_table()
{
    for (int i = 0; i < N; i++) printf("%d ", dp[i]); printf("\n");
}


void solve()
{
    S[0] = A[0].L;
    for (int i = 1; i < N; i++) S[i] = S[i-1] + A[i].L;
    for (int i = 0; i < N; i++) dp[i] = INF;

    for (int i = 0; i < N; i++) {
        dp[i] = A[i].K + S[i] * A[i].C;
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + (S[i] - S[j]) * A[i].C + A[i].K);
        }
    }
    // print_table();
    printf("%d\n", dp[N-1]);
}


int main()
{
    while (scanf("%d", &N) == 1) {
        memset(dp, 0, sizeof(dp));
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d%d", &A[i].V, &A[i].K, &A[i].C, &A[i].L);
        }
        sort(A, A+N, compare);
        solve();
    }
}
