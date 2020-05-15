// UVa 1579
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 500+10;
// const int INF = 1 << 30;
int A[MAXN];
int N;
int dp[MAXN][MAXN];
stack<int> S;
stack<int> SS;

void print_table()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%2d ", dp[i][j]);
        printf("\n");
    }
}

int calc(int s, int t)
{
    int hasone = false;
    for (int i = s; i <= t; i++) if (A[i] == 1) { hasone = true; break; }
    if (!hasone) return -1;

    while (!S.empty()) S.pop();
    while (!SS.empty()) SS.pop();

    int sum = 0;
    for (int i = s; i <= t; i++) {
        if (S.empty()) { S.push(A[i]); }
        else if (S.top() < A[i]) { S.push(A[i]); sum++; }
        else if (S.top() == A[i]) { return -1; }
        else {
            while (!S.empty() && S.top() > A[i]) {
                SS.push(S.top()); S.pop();
                sum++;
            }
            if (!S.empty() && S.top() == A[i]) return -1;
            else {
                sum = (S.empty()) ? sum : sum + 1;
                S.push(A[i]);
                while (!SS.empty()) { S.push(SS.top()); SS.pop(); }
            }
        }
        // printf("now: sum = %d A[i] = %d\n", sum, A[i]);
    }

    return sum;
}

void solve()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) dp[i][j] = -1;
    }
    for (int l = 1; l <= N; l++) {
        for (int s = 0; s+l <= N; s++) {
            // printf("[%d, %d]\n", s, s+l-1);
            dp[s][s+l-1] = calc(s, s+l-1);
            for (int k = s+1; k <= s+l-3; k++) {
                int x = dp[s][k], y = dp[k+1][s+l-1];
                int &z = dp[s][s+l-1];
                if (x == -1 || y == -1) continue;

                if (z == -1) z = x + y;
                else z = min(z, x + y);
            }
        }
    }

    // print_table();
    if (dp[0][N-1] == -1) printf("impossible\n");
    else printf("%d\n", dp[0][N-1]);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        // printf("[0,2] %d [3,6] %d\n", calc(0, 2), calc(3, 6));
        solve();
    }
}
