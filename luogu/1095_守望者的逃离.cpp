// P1095 守望者的逃离
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

// const int MAXT = 300000+10;
const int MAXM = 1000 + 10;
int dp[2][MAXM];
int M, S, T;

void print_2darray(int a[2][MAXM], int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) printf("%d%c", a[i][j], j==c-1?'\n':' ');
}


int main()
{
    while (scanf("%d%d%d", &M, &S, &T) == 3) {
        memset(dp, 0, sizeof(dp));
        // printf("M, S, T %d %d %d\n", M, S, T);
        int m = 0, t = 0;
        for (int i = 1; i <= T; i++) {
            for (int j = 0; j <= M; j++) {
                dp[i%2][j] = dp[(i-1)%2][j] + 17;
                if (j - 4 >= 0) dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-4] + 0);
                if (j + 10 <= M) dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j+10] + 60);
                m = max(m, dp[i%2][j]);
            }
            if (m >= S) { t = i; break; }
        }
        // print_2darray(dp, T+1, M+1);
        // printf("m = %d t = %d\n", m, t);
        if (m >= S) printf("Yes\n%d\n", t);
        else printf("No\n%d\n", m);
    }
}
