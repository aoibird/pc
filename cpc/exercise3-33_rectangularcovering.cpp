// POJ 2836 Rectangular Covering
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 15;
PII A[MAXN]; // (x, y)
PII S[MAXN*MAXN]; // (set, area)
int N;
int dp[1 << MAXN];

int get_area(int a, int b)
{
    int fx = A[a].first, tx = A[b].first, fy = A[a].second, ty = A[b].second;
    return max(1, abs(ty - fy)) * max(1, abs(tx - fx));
}

bool iscover(PII &a, PII &b, PII &c)
{
    return (a.first-c.first)*(b.first-c.first)<=0
        && (a.second-c.second)*(b.second-c.second)<=0;
}

void solve()
{
    int C = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            S[C] = PII((1<<i)|(1<<j), get_area(i, j));
            for (int k = 0; k < N; k++) if (iscover(A[i], A[j], A[k])) S[C].first |= 1<<k;
            C++;
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int s = 0; s < (1<<N); s++) {
        for (int i = 0; i < C; i++) {
            dp[s|S[i].first] = min(dp[s|S[i].first], dp[s] + S[i].second);
        }
    }
    printf("%d\n", dp[(1<<N)-1]);
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%d%d", &A[i].first, &A[i].second);

        solve();
    }
}
