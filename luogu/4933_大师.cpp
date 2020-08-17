// Luogu 4933 大师
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

const int MOD = 998244353;
const int MAXN = 1000+10;
const int MAXD = 20000+10;
int A[MAXN];
int dp[MAXN][MAXD*2];
int N;

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        int sum = 0, D = 20000;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) {// end with tower i
            sum += 1;
            for (int j = 0; j < i; j++) {
                int d = A[i]-A[j];
                dp[i][d+D] = (dp[i][d+D] + dp[j][d+D] + 1) % MOD;
                sum = (sum + dp[j][d+D] + 1) % MOD;
            }
        }
        printf("%d\n", sum);
    }
}
