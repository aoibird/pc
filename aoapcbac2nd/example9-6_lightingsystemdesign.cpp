// UVa 11400
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
const int MAXN = 1000+10;
int V[MAXN], K[MAXN], C[MAXN], L[MAXN];
int S[MAXN];
int N;
int dp[MAXN];

void print_table()
{
    for (int i = 0; i < N; i++) printf("%d ", dp[i]); printf("\n");
}


void solve()
{
    S[0] = L[0];
    for (int i = 1; i < N; i++) S[i] = S[i-1] + L[i];
    for (int i = 0; i < N; i++) dp[i] = INF;

    for (int i = 0; i < N; i++) {
        dp[i] = K[i] + S[i] * C[i];
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + (S[i] - S[j]) * C[i] + K[i]);
        }
    }
    // print_table();
    printf("%d\n", dp[N-1]);
}


int main()
{
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        for (int i = 0; i < N; i++)
            scanf("%d%d%d%d", &V[i], &K[i], &C[i], &L[i]);
        solve();
    }
}
