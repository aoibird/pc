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
int R[MAXN];
int dp[MAXN];
int N;

int main()
{
    N = 0;
    while (scanf("%d", &A[N]) == 1) N++;
    for (int i = 0; i < N; i++) R[i] = A[N-i-1];

    fill(dp, dp+N, INF);
    for (int i = 0; i < N; i++) {
        *upper_bound(dp, dp+N, R[i]) = R[i];
    }
    printf("%ld\n", lower_bound(dp, dp+N, INF) - dp);

    fill(dp, dp+N, INF);
    for (int i = 0; i < N; i++) {
        *lower_bound(dp, dp+N, A[i]) = A[i];
    }
    printf("%ld\n", lower_bound(dp, dp+N, INF) - dp);
}
