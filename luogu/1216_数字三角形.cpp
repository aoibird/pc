// P1216 [USACO1.5][IOI1994]数字三角形 Number Triangles
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
int A[MAXN][MAXN];
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
        for (int l = 1; l <= N; l++) {
            for (int j = 0; j < l; j++) scanf("%d", &A[l][j]);
        }

        for (int j = 0; j < N; j++) dp[N][j] = A[N][j];
        for (int i = N-1; i >= 1; i--) {
            for (int j = 0; j < i; j++)
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + A[i][j];
        }
        // print_2darray(dp, N+1, N+1);
        // print_2darray(A, N+1, N+1);
        printf("%d\n", dp[1][0]);
    }
}
