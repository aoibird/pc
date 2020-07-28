// POJ 1631
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

const int MAXN = 40000+10;
const int INF = 0x3f3f3f;
int A[MAXN];
int dp[MAXN];
int N;

void solve()
{
    fill(dp, dp+N, INF);
    for (int i = 0; i < N; i++) {
        *lower_bound(dp, dp+N, A[i]) = A[i];
    }
    printf("%ld\n", lower_bound(dp, dp+N, INF) - dp);
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        memset(dp, 0, sizeof(dp));

        solve();
    }
}
