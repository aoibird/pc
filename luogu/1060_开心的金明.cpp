// P1060 开心的金明
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

const int MAXM = 25+5;
const int MAXN = 30000+10;
int V[MAXM];
int W[MAXM];
int dp[MAXN];
int N, M;

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        for (int i = 0; i < M; i++) scanf("%d%d", &V[i], &W[i]);
        for (int i = 0; i < M; i++) W[i] *= V[i];
        for (int i = 0; i < M; i++) {
            for (int j = N; j >= V[i]; j--) {
                dp[j] = max(dp[j], dp[j-V[i]] + W[i]);
            }
        }
        printf("%d\n", dp[N]);
    }
}
