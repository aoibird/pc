// POJ 3666
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
const int MAXN = 2000+10;
int A[MAXN];
int B[MAXN];
int dp[MAXN][MAXN];
int N;

void solve()
{
    for (int j = 0; j < N; j++) dp[0][j] = abs(A[0] - B[j]);
    for (int i = 1; i < N; i++) {
        int m = dp[i-1][0];
        for (int j = 0; j < N; j++) {
            m = min(m, dp[i-1][j]);
            dp[i][j] = m + abs(A[i] - B[j]);
        }
    }
    int m = INF;
    for (int j = 0; j < N; j++) m = min(m, dp[N-1][j]);
    printf("%d\n", m);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]); }
        for (int i = 0; i < N; i++) B[i] = A[i];
        sort(B, B+N);
        solve();
    }
}
