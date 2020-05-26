// UVa 227
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

const int MAXL = 1000000;
const int N = 5;
char F[N][N];
int R, C;
char S[MAXL];
int cnt;

void input()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            F[i][j] = getchar();
            if (F[i][j] == ' ') { R = i; C = j; }
        }
        getchar();
    }

    cnt = 0;
    int ch;
    while ((ch = getchar())!=EOF && ch!='0') {
        if (ch == 'A' || ch == 'B' || ch == 'L' || ch == 'R') S[cnt++] = ch;
    }
    getchar();
}

void print_field()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c%c", F[i][j], j==N-1?'\n':' ');
        }
    }
}

void solve()
{
    // print_field();
    // for (int i = 0; i < cnt; i++) printf("%c ", S[i]); printf("\n");

    bool invalid = false;
    for (int i = 0; i < cnt; i++) {
        char ch = S[i];
        if (ch == 'A') {
            if (R-1 < 0) { invalid = true; break; }
            else { F[R][C] = F[R-1][C]; R = R-1; F[R][C] = ' '; }
        }
        else if (ch == 'B') {
            if (R+1 >= N) { invalid = true; break; }
            else { F[R][C] = F[R+1][C]; R = R+1; F[R][C] = ' '; }
        }
        else if (ch == 'L') {
            if (C-1 < 0) { invalid = true; break; }
            else { F[R][C] = F[R][C-1]; C = C-1; F[R][C] = ' '; }
        }
        else if (ch == 'R') {
            if (C+1 >= N) { invalid = true; break; }
            else { F[R][C] = F[R][C+1]; C = C+1; F[R][C] = ' '; }
        }
        else ;
    }

    if (invalid) printf("This puzzle has no final configuration.\n");
    else print_field();
}

int main()
{
    int ch;
    int tc = 1;
    while ((ch = getchar()) != EOF && ch != 'Z') {
        ungetc(ch, stdin);
        input();

        printf("Puzzle #%d:\n", tc); tc++;
        solve();
        printf("\n");
    }
}
