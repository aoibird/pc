// LOJ 507 「LibreOJ NOI Round #1」接竹竿
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

const int MAXN = 1e6;
int N, K;
ll COLORS[MAXN], VALUES[MAXN];
ll S[MAXN];
ll DP[MAXN];

ll sum(int from, int to)
{
    return S[to] - S[from] + VALUES[from];
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) { scanf("%lld", &COLORS[i]); }
    for (int i = 0; i < N; i++) { scanf("%lld", &VALUES[i]); }
    S[0] = VALUES[0];
    for (int i = 1; i < N; i++) { S[i] = S[i-1] + VALUES[i]; }

    memset(DP, 0, sizeof(DP));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            DP[i] = max(DP[i], (j > 0 ? DP[j-1] : 0) + (COLORS[j] == COLORS[i] ? sum(j, i) : 0));
        }
    }
    // for (int i = 0; i < N; i++) { printf("%lld%c", DP[i], (i+1==N?'\n':' ')); }
    printf("%lld\n", DP[N-1]);
}
