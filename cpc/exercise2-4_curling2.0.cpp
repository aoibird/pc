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

const int MAXR = 20+5;
const int MAXC = 20+5;

int F[MAXR][MAXC];

struct State {
    int r, c, step;
    vector<PII> blocks;
    State(int ri=0, int ci=0, int si=0) {
        r=ri; c=ci; step=si;
        blocks.resize(0);
    }
};

int R, C;
int SR, SC, GR, GC;
queue<State> q;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void print_field(int f[MAXR][MAXC])
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) { printf("%d ", f[i][j]); }
        printf("\n");
    }
}

bool move(State &curr, int ir, int ic, State &nxt)
{
    for (int i = 0; i < curr.blocks.size(); i++) {
        PII p = curr.blocks[i]; int a = p.first, b = p.second;
        F[a][b] = 0;
        nxt.blocks.push_back(p);
    }
    bool cont = false;
    // printf("r = %d c = %d\n", curr.r, curr.c);
    for (int r = curr.r, c = curr.c;  ; r += ir, c += ic) {
        if (r < 0 || r >= R || c < 0 || c >= C) { // out
            break;
        }
        else if (F[r][c] == 1 && r - ir == curr.r && c - ic == curr.c) {
            break;
        }
        else if (F[r][c] == 1) { // hit
            nxt.r = r - ir;
            nxt.c = c - ic;
            nxt.step = curr.step + 1;
            nxt.blocks.push_back(PII(r, c));
            cont = true;
            break;
        }
        else if (F[r][c] == 3) { // goal
            nxt.r = r;
            nxt.c = c;
            nxt.step = curr.step + 1;
            cont = true;
            break;
        }
        else {}
    }
    // printf("    nextr = %d nextc = %d %d (%d)\n", nxt.r, nxt.c, nxt.step, cont);
    for (int i = 0; i < curr.blocks.size(); i++) {
        PII p = curr.blocks[i]; int a = p.first, b = p.second;
        F[a][b] = 1;
    }

    return cont;
}

void solve()
{
    State curr, nxt;
    q.push(State(SR, SC, 0));

    int step = -1;
    while (!q.empty()) {
        curr = q.front(); q.pop();
        if (curr.step > 10) { break; }
        if (curr.r == GR && curr.c == GC) { step = curr.step; break; }

        for (int i = 0; i < 4; i++) {
            bool ret = move(curr, dr[i], dc[i], nxt);
            if (ret) {
                q.push(nxt);
            }
        }
    }

    while (!q.empty()) q.pop();
    printf("%d\n", step);
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
