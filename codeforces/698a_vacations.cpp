#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100+10;
const int INF = 1000000;
int A[MAXN];
int N;
int dp[MAXN][3]; // rest, contest, gym


void get_event(int x, bool &contest, bool &gym)
{
    if (A[x] == 0) { contest = gym = false; }
    else if (A[x] == 1) { contest = true; gym = false; }
    else if (A[x] == 2) { contest = false; gym = true; }
    else if (A[x] == 3) { contest = gym = true; }
    else ;
}

void print_table()
{
    bool contest, gym;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) printf("%d ", dp[i][j]);
        get_event(i, contest, gym);
        printf("(%d %d %d)\n", A[i], (int)contest, (int)gym);
    }
    printf("\n");
}


void solve()
{
    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) dp[i][j] = INF;
    // print_table();

    bool event[3]; // rest, contest, gym
    get_event(0, event[1], event[2]);
    dp[0][0] = 1;
    for (int i = 1; i <= 2; i++) if (event[i]) { dp[0][i] = 0; }

    for (int i = 0; i < N-1; i++) {
        event[0] = true;
        get_event(i+1, event[1], event[2]);

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (a == 0 && event[b])
                    dp[i+1][b] = min(dp[i+1][b], dp[i][a] + (b==0?1:0));
                if (a != 0 && a != b && event[b])
                    dp[i+1][b] = min(dp[i+1][b], dp[i][a] + (b==0?1:0));
            }
        }
    }

    // print_table();
    int ans = INF;
    for (int j = 0; j < 3; j++) ans = min(ans, dp[N-1][j]);
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        solve();
    }
}
