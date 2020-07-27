// POJ 3046
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXA = 1e5+20; // ants
const int MAXT = 1e3+10; // types
const int MAXS = MAXA;   // sizes
const int M = 1e6;
int U[MAXT];
int dp[MAXT][MAXS];
int T, A, S, B;

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


int main()
{
    vector<int> t;
    while (scanf("%d%d%d%d", &T, &A, &S, &B) == 4) {
        memset(U, 0, sizeof(U));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < A; i++) { int a; scanf("%d", &a); U[a-1] += 1; }
        // print_array(U, A);

        int sum = 0;
        for (int i = 0; i <= T; i++) dp[i][0] = 1;
        for (int i = 0; i < T; i++) { // types
            for (int j = 1; j <= B; j++) { // sizes
                if (j-1-U[i] >= 0) dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-U[i]] + M) % M;
                else dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % M;
            }
        }
        // print_array(dp[T], B+1);
        for (int j = S; j <= B; j++) sum = (sum + dp[T][j]) % M;
        printf("%d\n", sum);
    }
}
