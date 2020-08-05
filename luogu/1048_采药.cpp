// P1048 采药
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

const int MAXT = 1000+10;
const int MAXM = 100+10;
int A[MAXM];
int V[MAXM];
int dp[MAXT];
int T, M;

int main()
{
    while (scanf("%d%d", &T, &M) == 2) {
        for (int i = 0; i < M; i++) scanf("%d%d", &A[i], &V[i]);

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < M; i++) {
            for (int j = T; j >= A[i]; j--) {
                dp[j] = max(dp[j], dp[j-A[i]] + V[i]);
            }
        }
        printf("%d\n", dp[T]);
    }
}
