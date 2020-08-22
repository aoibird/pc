// POJ 3254 Corn Fields
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

const int MOD = 1e9;
const int MAXMN = 12+1;
int field[MAXMN];
int M, N;
int dp[2][1 << MAXMN];
bool dislike[1 << MAXMN];

void get_dislike()
{
    for (int s = 0; s < (1<<N); s++) {
        for (int j = 0; j < N; j++)
            if (((s>>j)&3) == 3) { dislike[s] = true; break; }
    }
}

void solve()
{
    memset(dislike, 0, sizeof(dislike));
    memset(dp, 0, sizeof(dp));
    get_dislike();

    for (int i = 0; i < M; i++) { // row
        memset(dp[i&1], 0, sizeof(dp[i&1]));
        for (int s = 0; s < (1<<N); s++) { // combination
            if ((s&(~field[i])) != 0) continue; // infertile
            if (dislike[s]) continue; // adjacent

            if (i == 0) { dp[i&1][s] = 1; continue; }
            for (int t = 0; t < (1<<N); t++) {
                if ((s&t) == 0 && dp[(i-1)&1][t])
                    dp[i&1][s] = (dp[i&1][s] + dp[(i-1)&1][t]) % MOD;
            }
        }
        // for (int s = 0; s < (1<<N); s++) printf("%2d ", s); printf("\n");
        // for (int s = 0; s < (1<<N); s++) printf("%2d ", dp[i&1][s]); printf("\n");
    }

    int cnt = 0;
    for (int s = 0; s < (1<<N); s++) cnt = (cnt+dp[(M-1)&1][s]) % MOD;
    printf("%d\n", cnt);
}

int main()
{
    while (scanf("%d%d", &M, &N) == 2) {
        memset(field, 0, sizeof(field));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) { int x; scanf("%d", &x); field[i] |= x<<j; }
        }

        solve();
    }
}
