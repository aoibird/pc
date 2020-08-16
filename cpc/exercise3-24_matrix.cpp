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
ll BIT[MAXN][MAXN];

ll sum(ll bit[MAXN][MAXN], int x, int y)
{
    ll s = 0;
    for (int i = x; i > 0; i-=i&-i)
        for (int j = y; j > 0; j-=j&-j) s += bit[i][j];
    return s;
}

void add(ll bit[MAXN][MAXN], int r, int c, int x, int y, int d)
{
    for (int i = x; i <= r; i+=i&-i)
        for (int j = y; j <= c; j+=j&j) bit[i][j] += d;
}

void solve()
{
    for (int i = 0; i < T; i++) {
        if (I[i] == 'C') {
            // printf("%c: %d %d %d %d\n", I[i], X1[i], Y1[i], X2[i], Y2[i]);
            add(BIT, N+1, N+1, X1[i], Y1[i], 1);
            add(BIT, N+1, N+1, X1[i], Y2[i]+1, -1);
            add(BIT, N+1, N+1, X2[i]+1, Y1[i], -1);
            add(BIT, N+1, N+1, X2[i]+1, Y2[i]+1, 1);
        }
        else {
            // printf("%c: %d %d\n", I[i], X1[i], Y1[i]);
            ll t = sum(BIT, X1[i], Y1[i]);
            printf("%lld\n", t%2);
        }
    }
}

int main()
{
    int TC; scanf("%d", &TC);
    int ch;
    for (int i = 0; i < TC; i++) {
        // printf("N == %d T == %d\n", N, T);
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
