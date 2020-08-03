// P1091 合唱队形
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

const int INF = 1e9;
const int MAXN = 100+10;
int A[MAXN];
int dp[MAXN];
int N;

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


bool cmp(const int &a, const int &b) { return a > b; }

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        memset(dp, 0, sizeof(dp));
        int m = 0;
        for (int i = 1; i < N-1; i++) {
            fill(dp, dp+i+1, INF);
            for (int j = 0; j < i+1; j++) {
                *lower_bound(dp, dp+i+1, A[j]) = A[j];
            }
            int l1 = lower_bound(dp, dp+i+1, INF) - dp;
            fill(dp+i, dp+N, 0);
            for (int j = i; j < N; j++) {
                *lower_bound(dp+i, dp+N, A[j], cmp) = A[j];
            }
            int l2 = lower_bound(dp+i, dp+N, 0, cmp) - (dp+i);
            m = max(m, l1 + l2 - 1);
            // printf("%d = %d + %d - 1(%d)\n", l1+l2-1, l1, l2, m);
        }
        printf("%d\n", N-m);
    }
}
