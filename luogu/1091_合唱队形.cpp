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
int L[MAXN][MAXN];
int R[MAXN][MAXN];
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

        memset(dp, 0, sizeof(dp));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        for (int i = 0; i < N; i++) { dp[i][i] = 1; L[i][i] = R[i][i] = i; }
        for (int i = N-1; i >= 0; i--) {
            for (int j = i+1; j <= N-1; j++) {
                int l, r;
                l = L[i+1][j], r = R[i+1][j];
                if (dp[i+1][j] + (A[i] < A[l]) > dp[i][j]) {
                    dp[i][j] = dp[i+1][j] + (A[i] < A[l]);
                    L[i][j] = (A[i] >= A[l]) ? l : i;
                    R[i][j] = (A[j] >= A[r]) ? r : j;
                    // printf("1 ");
                }

                l = L[i][j-1], r = R[i][j-1];
                if (dp[i][j-1] + (A[j] < A[r]) > dp[i][j]) {
                    dp[i][j] = dp[i][j-1] + (A[j] < A[r]);
                    L[i][j] = (A[i] >= A[l]) ? l : i;
                    R[i][j] = (A[j] >= A[r]) ? r : j;
                    // printf("2 ");
                }

                // printf("(%d, %d): %d %d %d\n", i, j, dp[i][j], L[i][j], R[i][j]);
            }
        }
        // print_2darray(dp, N, N);
        // print_2darray(L, N, N);
        // print_2darray(R, N, N);
        printf("%d\n", N-dp[0][N-1]);
    }
}
