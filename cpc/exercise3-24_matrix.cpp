// POJ 2155 Matrix
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef int ll;
typedef pair<int,int> PII;

const int MAXN = 1000+5;
int A[MAXN][MAXN];
int N, T;
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
        for (int j = y; j <= c; j+=j&-j) bit[i][j] += d;
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
            ch = getchar();
            if (ch == 'C') {
                int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                add(BIT, N+1, N+1, x1, y1, 1);
                add(BIT, N+1, N+1, x1, y2+1, -1);
                add(BIT, N+1, N+1, x2+1, y1, -1);
                add(BIT, N+1, N+1, x2+1, y2+1, 1);
            }
            else {
                int x, y;
                scanf("%d%d", &x, &y);
                ll t = sum(BIT, x, y);
                printf("%d\n", t%2);
            }
            while ((ch = getchar()) != EOF && ch != '\n') ;
        }

        if (i+1 != TC) printf("\n");
    }
}
