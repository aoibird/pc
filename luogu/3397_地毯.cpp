// Luogu 3397 地毯
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
int A[MAXN];
int N, M;
int BIT[MAXN][MAXN];

int sum(int bit[MAXN][MAXN], int x, int y)
{
    int s = 0;
    for (int i = x; i > 0; i-=i&-i) {
        for (int j = y; j > 0; j-=j&-j) s += bit[i][j];
    }
    return s;
}

void add(int bit[MAXN][MAXN], int n, int x, int y, int d)
{
    for (int i = x; i <= n; i+=i&-i) {
        for (int j = y; j <= n; j+=j&-j) bit[i][j] += d;
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        add(BIT, N, x1, y1, 1);
        add(BIT, N, x2+1, y1, -1);
        add(BIT, N, x1, y2+1, -1);
        add(BIT, N, x2+1, y2+1, 1);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) printf("%d%c", sum(BIT,i,j), j==N?'\n':' ');
    }

}
