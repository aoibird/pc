// P1880 [NOI1995]石子合并
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

const int INF = 1e9;
const int MAXN = 100*2+20;
int A[MAXN];
int dp[MAXN][MAXN];
int smin[MAXN][MAXN];
int smax[MAXN][MAXN];
int N, S;

void print_2darray(int a[MAXN][MAXN], int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) printf("%d%c", a[i][j], j==c-1?'\n':' ');
}


int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]); S += A[i]; }
        for (int i = 0; i < N; i++) A[i+N] = A[i];

        memset(dp, 0, sizeof(dp));
        int sum_min = INF, sum_max = 0;
        for (int i = 0; i < N; i++) { dp[i][i] = smin[i][i] = smax[i][i] = A[i]; }
        for (int l = 2; l <= N; l++) {// length
            for (int i = 0; i <= N-1; i++) {// [i, j]
                int j = (i+l-1)%N;
                smin[i][j] = INF, smax[i][j] = 0;
                for (int k = 0; k < l-1; k++) {// split
                    int modk = (i+k)%N, modk1 = (i+k+1)%N;
                    dp[i][j] = dp[i][modk] + dp[modk1][j];
                    smin[i][j] = min(smin[i][j], dp[i][j] + (i==modk?0:smin[i][modk])
                                     + (modk1==j?0:smin[modk1][j]));
                    smax[i][j] = max(smax[i][j], dp[i][j] + (i==modk?0:smax[i][modk])
                                     + (modk1==j?0:smax[modk1][j]));
                }
                if (l == N) {
                    sum_min = min(sum_min, smin[i][j]);
                    sum_max = max(sum_max, smax[i][j]);
                }
                else ;
            }
        }
        // print_2darray(dp, N, N); printf("\n");
        // print_2darray(smin, N, N); printf("\n");
        // print_2darray(smax, N, N); printf("\n");
        printf("%d\n%d\n", sum_min, sum_max);
    }
}
