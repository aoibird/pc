// UVa 1626
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXL = 200+10;
char S[MAXL];
int dp[MAXL][MAXL];
int N;

void strip() { int ch; while ((ch = getchar()) != EOF && ch != '\n') ; }

bool match(char a, char b) { return (a=='('&&b==')') || (a=='['&&b==']'); }

void print(int i, int j)
{
    if (i > j) return;

    if (i == j) {
        if (S[i] == '(' || S[i] == ')') printf("()");
        else printf("[]");
    }
    else {
        int ans = dp[i][j];
        if (match(S[i], S[j]) && ans == dp[i+1][j-1]) {
            printf("%c", S[i]); print(i+1, j-1); printf("%c", S[j]);
        }
        else {
            for (int k = i; k < j; k++) {
                if (ans == dp[i][k]+dp[k+1][j]) { print(i, k); print(k+1, j); return; }
            }
        }
    }
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) { dp[i+1][i] = 0; dp[i][i] = 1; }

    for (int i = N-2; i >= 0; i--) {
        for (int j = i+1; j < N; j++) {
            dp[i][j] = N;
            if (match(S[i], S[j])) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            for (int k = i; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
        }
    }
}

int main()
{
    int TC; scanf("%d", &TC); strip();
    for (int i = 0; i < TC; i++) {
        strip();
        int ch; N = 0;
        while ((ch = getchar()) != EOF && ispunct(ch)) { S[N++] = ch; }
        S[N] = '\0';

        solve();
        print(0, N-1);
        (i+1 == TC) ? printf("\n") : printf("\n\n");
    }
}
