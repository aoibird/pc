// P1095 守望者的逃离
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

const int MAXT = 300000+10;
// const int MAXM = 1000 + 10;
int dp[MAXT];
int M, S, T;

int main()
{
    while (scanf("%d%d%d", &M, &S, &T) == 3) {
        memset(dp, 0, sizeof(dp));
        // printf("M, S, T %d %d %d\n", M, S, T);
        for (int i = 1; i <= T; i++) {
            if (M >= 10) { dp[i] = dp[i-1]+60; M -= 10; }
            else { dp[i] = dp[i-1], M += 4; }
        }
        int i;
        for (i = 1; i <= T; i++) {
            dp[i] = max(dp[i], dp[i-1] + 17);
            if (dp[i] >= S) break;
        }
        if (dp[i] >= S) printf("Yes\n%d\n", i);
        else printf("No\n%d\n", dp[T]);
    }
}
