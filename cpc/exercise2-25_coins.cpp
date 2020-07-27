// POJ 1742
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

const int MAXN = 100+10;
const int MAXM = 1e5+10;
int A[MAXN];
int C[MAXN];
bool dp[MAXM];
int v[MAXM];
int N, M;

void print_array(bool a[MAXN], int n) {
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


void solve()
{
    dp[0] = true;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i], c = C[i];
        memset(v, 0, sizeof(v));
        for (int j = a; j <= M; j++) {
            if (!dp[j] && dp[j-a] && v[j-a] < c) {
                dp[j] = true; v[j] = v[j-a]+1; cnt++;
            }
        }
    }
    // print_array(dp, upper + A[N-1]*C[N-1]);
    printf("%d\n", cnt);
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]); }
        for (int i = 0; i < N; i++) { scanf("%d", &C[i]); }
        solve();
    }
}
