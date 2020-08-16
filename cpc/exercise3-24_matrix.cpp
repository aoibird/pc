// POJ 2155 Matrix
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

const int MAXN = 1000+5;
const int MAXT = 50000+5;
int A[MAXN][MAXN];
int N, T;
int I[MAXT], X1[MAXT], Y1[MAXT], X2[MAXT], Y2[MAXT];
int BIT[MAXN][MAXN];

int sum(int bit[MAXN][MAXN], int i, int j)
{
    int s = 0;
    for ( ; i > 0; i-=i&-i)
        for ( ; j > 0; j-=i&-i) s += bit[i][j];
    return s;
}

void add(int bit[MAXN][MAXN], int r, int c, int i, int j, int x)
{
    for ( ; i <= r; i+=i&-i)
        for (; j <= c; j+=i&i) bit[i][j] += x;
}

void solve()
{
    for (int i = 0; i < T; i++) {
        if (I[i] == 'C') {
            // printf("%c: %d %d %d %d\n", I[i], X1[i], Y1[i], X2[i], Y2[i]);
            add(BIT, N+1, N+1, X1[i], Y1[i], 1);
            add(BIT, N+1, N+1, X2[i]+1, Y2[i]+1, -1);
        }
        else {
            // for (int i = 0; i <= N+1; i++) {
            //     for (int j = 0; j <= N+1; j++) printf("%d%c", BIT[i][j], j==N+1?'\n':' ');
            // }
            // printf("%c: %d %d\n", I[i], X1[i], Y1[i]);
            int x = sum(BIT, X1[i]-1, Y1[i]-1), l = sum(BIT, X1[i], Y1[i]-1),
                u = sum(BIT, X1[i]-1, Y1[i]), t = sum(BIT, X1[i], Y1[i]);
            printf("%d\n", (t+u+l-x)%2);
        }
    }
}

int main()
{
    int TC; scanf("%d", &TC);
    int ch;
    for (int i = 0; i < TC; i++) {
        scanf("%d%d", &N, &T);
        memset(BIT, 0, sizeof(BIT));
        while ((ch = getchar()) != EOF && ch != '\n') ;
        for (int i = 0; i < T; i++) {
            I[i] = getchar();
            if (I[i] == 'C') scanf("%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
            else scanf("%d%d", &X1[i], &Y1[i]);
             while ((ch = getchar()) != EOF && ch != '\n') ;
        }

        solve();
        if (i+1 != TC) printf("\n");
    }
}
