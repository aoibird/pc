// Luogu 1064 金明的预算方案
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

struct Stuff {
    int v, w, q, vw;
    Stuff(int vi=0, int wi=0, int qi=0) { v=vi; w=wi; q=qi; vw=vi*wi; }
};

const int MAXN = 32000+5;
Stuff A[MAXN];
int dp[MAXN];
int N, M;

bool cmp(const Stuff &a, const Stuff &b) { return a.q<b.q; }

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < N; i++) {
            int v, w, q; scanf("%d%d%d", &v, &w, &q);
            A[i] = Stuff(v, w, q);
        }
        sort(A, A+N, cmp);

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < M; i++) {
            for (int j = N; j >= A[i].v; j--) {
                dp[j] = max(dp[j], dp[j-A[i].v] + A[i].vw);
            }
        }
        printf("%d\n", dp[N]);
    }
}
