// UVa 232
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

const int MAXR = 10+5;
const int MAXC = 10+5;
char F[MAXR][MAXC];
char T[MAXR][MAXC];
int R, C;

void print_field()
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) printf("%c", F[i][j]);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) printf("%2d ", T[i][j]);
        printf("\n");
    }
    printf("\n");
}

void input()
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            F[i][j] = getchar();
        }
        getchar();
    }
}

void print_across(int x, int y)
{
    printf("%3d.", T[x][y]);
    for (int i = y; i < C && F[x][i] != '*'; i++) printf("%c", F[x][i]);
    printf("\n");
}

void print_down(int x, int y)
{
    printf("%3d.", T[x][y]);
    for (int i = x; i < R && F[i][y] != '*'; i++) printf("%c", F[i][y]);
    printf("\n");
}

void solve()
{
    memset(T, 0, sizeof(T));
    int cnt = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if ((i-1 < 0 || j-1 < 0 || F[i-1][j] == '*' || F[i][j-1] == '*')
                && F[i][j] != '*')
                T[i][j] = cnt++;
        }
    }
    // printf("%d %d\n", R, C);
    // print_field();
    printf("Across\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if ((j-1 < 0 || F[i][j-1] == '*') && T[i][j] > 0)
                print_across(i, j);
        }
    }
    printf("Down\n");
    for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
            if ((i-1 < 0 || F[i-1][j] == '*') && T[i][j] > 0)
                print_down(i, j);
        }
    }
}

int main()
{
    int tc = 1;
    while (scanf("%d%d", &R, &C) == 2) {
        getchar();
        input();

        if (tc != 1) printf("\n");
        printf("puzzle #%d:\n", tc); tc++;
        solve();
    }
}
