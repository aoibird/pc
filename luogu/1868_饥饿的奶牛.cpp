// P1868 饥饿的奶牛
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

const int MAXN = 150000+10;
PII A[MAXN];
int dp[MAXN];
int N;

bool cmp(const PII &a, const PII &b)
{
    return a.second<b.second || (a.second==b.second && a.first<b.first);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d%d", &A[i].first, &A[i].second);

        sort(A, A+N, cmp);
        for (int i = 0; i < N; i++) {
            dp[i] = A[i].second - A[i].first + 1;
            for (int j = 0; j < i; j++) {
                if (A[j].second < A[i].first)
                    dp[i] = max(dp[i], dp[j] + A[i].second - A[i].first + 1);
                else
                    dp[i] = max(dp[i], dp[j]);
            }
        }

        printf("%d\n", dp[N-1]);
    }
}
