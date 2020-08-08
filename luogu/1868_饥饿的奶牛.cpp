// P1868 饥饿的奶牛
#include <cctype>
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

const int MAXN = 150000+10;
PII A[MAXN];
int dp[MAXN];
int R[MAXN];
int N;

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


bool cmp(const PII &a, const PII &b)
{
    return a.second<b.second || (a.second==b.second && a.first<b.first);
}


int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d%d", &A[i].first, &A[i].second);

        sort(A, A+N, cmp);
        for (int i = 0; i < N; i++) R[i] = A[i].second;
        // print_array(R, N);
        dp[0] = A[0].second-A[0].first+1;
        for (int i = 1; i < N; i++) {
            dp[i] = max(dp[i-1], A[i].second-A[i].first+1);
            int p = lower_bound(R, R+i, A[i].first) - R - 1;
            if (p >= 0) dp[i] = max(dp[i], dp[p] + A[i].second-A[i].first+1);
        }

        printf("%d\n", dp[N-1]);
    }
}
