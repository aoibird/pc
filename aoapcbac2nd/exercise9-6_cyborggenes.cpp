// UVa 10723
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

const int INF = 0x3f3f3f3f;
const int MAXL = 30*2;
char A[MAXL], B[MAXL];
int dp[MAXL][MAXL];
int cnt[MAXL][MAXL];
int NA, NB;

int dx[3] = {-1, 0, -1};
int dy[3] = {0, -1, -1};

void print_2darray(int a[MAXL][MAXL], int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) printf("%2d%c", a[i][j], j==c-1?'\n':' ');
}


void solve()
{
    for (int i = 0; i <= NA; i++) fill(dp[i], dp[i]+NB+1, INF);
    for (int i = 0; i <= NA; i++) { dp[i][0] = i; }
    for (int j = 0; j <= NB; j++) { dp[0][j] = j; }
    for (int i = 1; i <= NA; i++) {
        for (int j = 1; j <= NB; j++) {
            if (A[i] == B[j]) { dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);  }
            dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1]) + 1);
            // printf("%c %c %d\n", A[i], B[j], dp[i][j]);
        }
    }

    for (int i = 0; i <= NA; i++) { cnt[i][0] = 1; }
    for (int j = 0; j <= NB; j++) { cnt[0][j] = 1; }
    for (int i = 1; i <= NA; i++) {
        for (int j = 1; j <= NB; j++) {
            if (A[i] == B[j]) { cnt[i][j] = cnt[i-1][j-1]; }
            else if (dp[i][j-1] > dp[i-1][j]) { cnt[i][j] = cnt[i-1][j]; }
            else if (dp[i][j-1] < dp[i-1][j]) { cnt[i][j] = cnt[i][j-1]; }
            else { cnt[i][j] = cnt[i-1][j] + cnt[i][j-1]; }
            // printf("%d(%c) %d(%c) %d\n", i, A[i], j, B[j], cnt[i][j]);
        }
    }
    // print_2darray(dp, NA+1, NB+1); printf("\n");
    // print_2darray(cnt, NA+1, NB+1); printf("\n");
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        scanf("%s", A+1); scanf("%s", B+1);
        NA = strlen(A+1); NB = strlen(B+1);

        solve();
        printf("Case #%d: %d %d\n", tc, dp[NA][NB], cnt[NA][NB]);
    }
}
