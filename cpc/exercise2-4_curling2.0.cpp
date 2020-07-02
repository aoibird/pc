// POJ 3009
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

const int INF = 10000;
const int MAXR = 20+5;
const int MAXC = 20+5;
int F[MAXR][MAXC];
int R, C;
int SR, SC, GR, GC;
int best;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void print_field(int f[MAXR][MAXC])
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) { printf("%d ", f[i][j]); }
        printf("\n");
    }
}

void dfs(int curr, int curc, int dirr, int dirc, int &step)
{
    // printf("curr r = %d c = %d (%d)\n", curr, curc, step);
    if (step > 10) return;
    if (F[curr + dirr][curc + dirc] == 1) return;

    int r = curr, c = curc;
    for ( ;  ; r += dirr, c += dirc) {
        if (r < 0 || r >= R || c < 0 || c >= C) { return; } // out
        else if (F[r][c] == 1) { break; } // hit
        else if (F[r][c] == 3) { best = min(best, step + 1); return; } // goal
        else {}
    }
    // printf("    next %d %d\n", r - dirr, c - dirc);
    F[r][c] = 0;
    for (int i = 0; i < 4; i++) {
        step += 1;
        dfs(r - dirr, c - dirc, dr[i], dc[i], step);
        step -= 1;
    }
    F[r][c] = 1;
}

void solve()
{
    best = INF;
    int step;
    for (int i = 0; i < 4; i++) {
        step = 0;
        dfs(SR, SC, dr[i], dc[i], step);
    }

    printf("%d\n", (best>10)?-1:best);
}

int main()
{
    while (scanf("%d%d", &C, &R) == 2) {
        if (R == 0 && C == 0) break;
        // printf("R = %d C = %d\n", R, C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%d", &F[i][j]);
                if (F[i][j] == 2) { SR = i; SC = j; F[i][j] = 0; }
                else if (F[i][j] == 3) { GR = i; GC = j; }
                else {}
            }
        }
        // print_field(F);

        solve();
    }
}
