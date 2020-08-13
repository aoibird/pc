// AOJ 0531 Paint Color ペンキの色
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 1000+5;
int X1[MAXN], X2[MAXN], Y1[MAXN], Y2[MAXN];
int W, H, N;
bool field[MAXN*6][MAXN*6];

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void print_field()
{
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            printf("%d ", field[y][x]);
        }
        printf("\n");
    }
}

int compress(int *z1, int *z2, int w)
{
    vector<int> zs;
    for (int i = 0; i < N; i++) {
        for (int d = -1; d <= 1; d++) {
            int tz1 = z1[i] + d, tz2 = z2[i] + d;
            if (0 <= tz1 && tz1 < w) zs.push_back(tz1);
            if (0 <= tz2 && tz2 < w) zs.push_back(tz2);
        }
    }
    sort(zs.begin(), zs.end());
    zs.erase(unique(zs.begin(), zs.end()), zs.end());

    for (int i = 0; i < N; i++) {
        z1[i] = find(zs.begin(), zs.end(), z1[i]) - zs.begin();
        z2[i] = find(zs.begin(), zs.end(), z2[i]) - zs.begin();
    }

    return zs.size();
}

void solve()
{
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    memset(field, 0, sizeof(field));
    for (int i = 0; i < N; i++) {
        for (int y = Y1[i]; y < Y2[i]; y++) {
            for (int x = X1[i]; x < X2[i]; x++) field[y][x] = true;
        }
    }

    int res = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            // printf("(%d %d)\n", x, y);
            if (field[y][x]) continue;
            res++;

            queue<PII> q;
            q.push(PII(x, y)); field[y][x] = true;
            while (!q.empty()) {
                PII p = q.front(); q.pop();
                int sx = p.first, sy = p.second;
                for (int i = 0; i < 4; i++) {
                    int tx = sx + dx[i], ty = sy + dy[i];
                    if (0 <= tx && tx < W && 0 <= ty && ty < H
                        && field[ty][tx]==false) {
                        q.push(PII(tx, ty));
                        field[ty][tx] = true;
                    }
                }
            }
        }
    }
    printf("%d\n", res);
}

int main()
{
    while (scanf("%d%d", &W, &H) == 2) {
        if (W == 0 && H == 0) break;
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);

        solve();
    }
}
