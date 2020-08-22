// POJ 2441 Arrange the Bulls
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

const int MAXNM = 20+2;
vector<int> P[MAXNM];
int dp[2][1 << MAXNM];
int N, M;

void solve()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        fill(dp[i&1], dp[i&1]+(1<<M), 0);
        for (int p = 0; p < P[i].size(); p++) {
            int t = 1 << P[i][p];
            if (i == 1) { dp[i&1][t] = 1; continue; } // i == 1
            for (int s = 0; s < (1 << M); s++) {      // i >= 1
                if (dp[(i-1)&1][s]!=0 && (t&s)==0) dp[i&1][t|s] += dp[(i-1)&1][s];
            }
        }
        // for (int s = 0; s < (1 << M); s++) printf("%2d ", s); printf("\n");
        // for (int s = 0; s < (1 << M); s++) printf("%2d ", dp[i&1][s]); printf("\n");
    }
    int cnt = 0;
    for (int s = 0; s < (1<<M); s++) cnt += dp[N&1][s];
    printf("%d\n", cnt);
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 1; i <= N; i++) {
            int c; scanf("%d", &c);
            for (int j = 0; j < c; j++) {
                int p; scanf("%d", &p);
                P[i].push_back(p-1);
            }
        }

        solve();
    }
}
