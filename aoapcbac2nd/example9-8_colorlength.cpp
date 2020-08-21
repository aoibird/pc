// UVa 1625 Color Length
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int COLORS = 30;
const int MAXNM = 5000+5;
char A[MAXNM], B[MAXNM];
int N, M;
int dp[2][MAXNM];
int cnt[2][MAXNM];
int SA[COLORS], EA[COLORS], SB[COLORS], EB[COLORS];


void solve()
{
    fill(SA, SA+COLORS, INF); fill(SB, SB+COLORS, INF);
    fill(EA, EA+COLORS, 0); fill(EB, EB+COLORS, 0);
    for (int i = 1; i <= N; i++) { int c = A[i]; SA[c] = min(SA[c], i); EA[c] = i; }
    for (int i = 1; i <= M; i++) { int c = B[i]; SB[c] = min(SB[c], i), EB[c] = i; }

    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0, t = 0; i <= N; i++, t ^= 1) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 && j == 0) continue;

            int v1 = (i >= 1) ? dp[t^1][j] + cnt[t^1][j] : INF;
            int v2 = (j >= 1) ? dp[t][j-1] + cnt[t][j-1] : INF;
            dp[t][j] = min(v1, v2);

            if (i >= 1) {
                cnt[t][j] = cnt[t^1][j];
                int color = A[i];
                if (SA[color] == i && SB[color] > j) cnt[t][j] += 1;
                if (EA[color] == i && EB[color] <= j) cnt[t][j] -= 1;
            }
            else if (j >= 1) {
                cnt[t][j] = cnt[t][j-1];
                int color = B[j];
                if (SB[color] == j && SA[color] > i) cnt[t][j] += 1;
                if (EB[color] == j && EA[color] <= i) cnt[t][j] -= 1;
            }
        }
    }
    printf("%d\n", dp[N&1][M]);
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        scanf("%s%s", A+1, B+1);
        N = strlen(A+1), M = strlen(B+1);
        for (int i = 1; i <= N; i++) A[i] -= 'A';
        for (int j = 1; j <= M; j++) B[j] -= 'A';

        solve();
    }
}
