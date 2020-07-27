// POJ 1742
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

const int MAXN = 100+10;
const int MAXM = 1e5+10;
int A[MAXN];
int C[MAXN];
bool dp[MAXM];
int N, M;

void print_array(bool a[MAXN], int n) {
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


void solve()
{
    dp[0] = true;
    int upper = 0;
    for (int i = 0; i < N; i++) {
        int a = A[i], c = C[i];
        for (int j = 0; j <= upper && j <= M - a*c; j++) {
            if (dp[j]) {
                for (int k = 1; k <= c; k++) { dp[j+a*k] = true; }
            }
        }
        for (int k = 1; k <= c; k++) { dp[a*k] = true; }
        upper += a*c;
        // printf("upper = %d\n", upper);
    }
    // print_array(dp, upper + A[N-1]*C[N-1]);
    int cnt = 0;
    for (int i = 1; i <= upper + A[N-1]*C[N-1] && i <= M; i++) if (dp[i]) cnt++;
    printf("%d\n", cnt);
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]); }
        for (int i = 0; i < N; i++) { scanf("%d", &C[i]); }
        solve();
    }
}
