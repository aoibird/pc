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
int A[MAXN];
int dp[MAXN];
int N;

void solve()
{
    int best = 0;
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        best = max(best, dp[i]);
    }
    printf("%d\n", best);
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
