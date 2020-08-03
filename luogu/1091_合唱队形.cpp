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

const int MAXN = 100+10;
int A[MAXN];
int dp[MAXN][MAXN];
int N;

void print_2darray(int a[MAXN][MAXN], int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) printf("%d%c", a[i][j], j==c-1?'\n':' ');
}


int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < N; i++) dp[i][i] = 0;
        for (int i = N-1; i >= 0; i--) {
            for (int j = i+1; j <= N-1; j++) {
                dp[i][j] = min(dp[i+1][j] + (A[i] >= A[i+1]),
                               dp[i][j-1] + (A[j] >= A[j-1]));
            }
        }
        // print_2darray(dp, N, N);
        printf("%d\n", dp[0][N-1]);
    }
}
