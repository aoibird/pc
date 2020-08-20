// LOJ 2424 子串
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

const int MOD = 1e9 + 7;
const int MAXN = 1000+5;
const int MAXM = 200+5;
int dp[MAXM][MAXM];
int S[MAXM][MAXM];
int N, M, K;
char A[MAXN], B[MAXM];

int main()
{
    scanf("%d%d%d%s%s", &N, &M, &K, A, B);

    S[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= 1; j--) {
            if (A[i-1] == B[j-1]) {
                for (int k = min(j, K); k >= 1; k--) {
                    dp[j][k] = (S[j-1][k-1] + dp[j-1][k]) % MOD;
                    S[j][k] = (S[j][k] + dp[j][k]) % MOD;
                }
            }
            else {
                for (int k = 0; k <= j && k <= K; k++) dp[j][k] = 0;
            }
        }
    }

    printf("%d\n", S[M][K]);
}
