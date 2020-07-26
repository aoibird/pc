// POJ 2385
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

const int MAXN = 1000+10;
int A[MAXN];
int dp[MAXN][MAXN];
int N, W;

void print_array(int a[MAXN], int n) {
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}

void print_2darray(int a[MAXN][MAXN], int r, int c)
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d%c", a[i][j], j==c-1?'\n':' ');
    }
}



int main()
{
    while (scanf("%d%d", &N, &W) == 2) {
        memset(A, 0, sizeof(A));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]);  A[i] -= 1; }
        // print_array(A, N);

        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= W; j++) {
                if (j & 1) dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + (A[i]==1?1:0);
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + (A[i]==0?1:0);
            }
        }
        // print_2darray(dp, N, W+1);

        printf("%d\n", dp[N-1][W]);
    }
}
