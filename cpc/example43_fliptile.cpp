// POJ 3279 Fliptile
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

const int WHITE = 0;
const int MAXM = 15+5;
const int MAXN = 15+5;
int tile[MAXM][MAXN];
int opt[MAXM][MAXN];
int flip[MAXM][MAXN];
int M, N;

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

int get_color(int x, int y)
{
    int c = tile[x][y];
    for (int i = 0; i < 5; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if (0 <= tx && tx < M && 0 <= ty && ty < N) c += flip[tx][ty];
    }
    return c % 2;
}

int calc()
{
    for (int i = 1; i < M; i++) {
        for (int j = 0; j < N; j++)
            if (get_color(i-1, j) != WHITE) flip[i][j] = 1;
    }

    for (int j = 0; j < N; j++) {
        if (get_color(M-1, j) != WHITE) return -1;
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) cnt += flip[i][j];
    }
    return cnt;
}

void solve()
{
    int res = -1;

    for (int i = 0; i < (1<<N); i++) {
        memset(flip, 0, sizeof(flip));
        for (int j = 0; j < N; j++) flip[0][N-j-1] = (i>>j)&1;
        int cnt = calc();

        if (cnt >= 0 && (res > cnt || res < 0)) {
            res = cnt;
            memcpy(opt, flip, sizeof(flip));
        }
    }

    if (res < 0) {
        printf("IMPOSSIBLE\n");
    }
    else {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) printf("%d%c", opt[i][j], j+1==N?'\n':' ');
        }
    }
}

int main()
{
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) scanf("%d", &tile[i][j]);
    }
    solve();
}
