// P1020 导弹拦截
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
const int MAXN = 1e5 + 10;
int A[MAXN];
int dp[MAXN];
int N;

int main()
{
    N = 0;
    while (scanf("%d", &A[N]) == 1) N++;

    int res[2];
    for (int t = 0; t < 2; t++) {
        fill(dp, dp+N, INF);
        for (int i = 0; i < N; i++) {
            *lower_bound(dp, dp+N, A[i]) = A[i];
        }
        res[t] = lower_bound(dp, dp+N, INF) - dp;
        for (int i = 0; i < N/2; i++) swap(A[i], A[N-i-1]);
    }
    printf("%d\n%d\n", res[1], res[0]);
}
