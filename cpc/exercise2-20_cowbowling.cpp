// POJ 3176
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

const int MAXN = 350+10;
int A[MAXN][MAXN];
int dp[MAXN][MAXN];
int N;

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
    while (scanf("%d", &N) == 1) {
        memset(dp, 0, sizeof(dp));
        memset(A, 0, sizeof(A));
        for (int r = 0; r < N; r++) {
            for (int i = 0; i < r+1; i++) scanf("%d", &A[r][i]);
        }
        // print_2darray(A, N, N);

        for (int r = N-1; r >= 0; r--) {
            for (int c = 0; c < r+1; c++) {
                dp[r][c] = max(dp[r+1][c], dp[r+1][c+1]) + A[r][c];
            }
        }
        // print_2darray(dp, N, N);
        printf("%d\n", dp[0][0]);
    }
}
