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
    return a.to < b.to || (a.to==b.to && a.from<b.from);
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

        dp[0] = A[0].eff;
        for (int i = 1; i < M; i++) {
            int f = A[i].from, e = A[i].eff;
            dp[i] = dp[i-1];
            for (int j = i-1; j >= 0; j--) {
                if (A[j].to <= f-R) dp[i] = max(dp[i], dp[j] + e);
                else dp[i] = max(dp[i], e);
            }
        }
        printf("%d\n", dp[M-1]);
    }
}
