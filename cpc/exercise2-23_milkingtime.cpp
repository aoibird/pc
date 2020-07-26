// POJ 3616
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

const int MAXM = 1000+10;
const int MAXN = 1000000+10;
struct Interval {
    int from, to, eff;
    Interval(int f=0, int t=0, int e=0) {
        from = f; to = t; eff = e;
    }
};

Interval A[MAXM];
int N, M, R;
int dp[MAXN];

bool cmp(const Interval &a, const Interval &b)
{
    return a.from < b.from || (a.from==b.from && a.to < b.to);
}

int main()
{
    while (scanf("%d%d%d", &N, &M, &R) == 3) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < M; i++) {
            int f, t, e; scanf("%d%d%d", &f, &t, &e);
            A[i].from = f, A[i].to = t, A[i].eff = e;
        }
        sort(A, A+M, cmp);

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < i; j++) {
                // printf("j -> i %d %d\n", j, i);
                for (int k = 0; k < M; k++) {
                    int f = A[k].from, t = A[k].to, e = A[k].eff;
                    if (j <= f-2 && t <= i) dp[i] = max(dp[i], dp[j] + e);
                    else if (dp[j] == 0 && f-2 <= 0 && t <= i) dp[i] = max(dp[i], e);
                    else ;
                }
            }
            // for (int j = 0; j <= N; j++) printf("%2d%c", dp[j], j==N?'\n':' ');
        }
        printf("%d\n", dp[N]);
    }
}
