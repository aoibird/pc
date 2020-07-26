// POJ 3280
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXM = 2000+10;
const int MAXN = 26+10;
int COST[MAXN];
char S[MAXM];
int dp[MAXM][MAXM];
int N, M;

void print_array(int a[MAXN], int n) {
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        memset(COST, 0, sizeof(COST)); memset(dp, 0, sizeof(dp));
        scanf("%s", S); getchar();
        for (int i = 0; i < N; i++) {
            char c; int a, d; scanf("%c%d%d", &c, &a, &d); getchar();
            COST[c-'a'] = min(a, d);
        }
        // print_array(COST, N);

        for (int i = M-1; i >= 0; i--) {
            for (int j = i+1; j < M; j++) {
                dp[i][j] = min(dp[i+1][j] + COST[S[i]-'a'],
                               dp[i][j-1] + COST[S[j]-'a']);
                if (S[i] == S[j]) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            }
        }
        printf("%d\n", dp[0][M-1]);
    }
}
