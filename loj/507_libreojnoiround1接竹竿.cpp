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
int COLORS[MAXN], VALUES[MAXN];
vector<int> M[MAXN];
ll S[MAXN];
ll DP[MAXN];

int main()
{

    scanf("%d%d", &N, &K);

    memset(DP, 0, sizeof(DP));
    for (int i = 0; i < K; i++) { M[i].clear(); }

    for (int i = 0; i < N; i++) { scanf("%d", &COLORS[i]); M[COLORS[i]].push_back(i); }
    for (int i = 0; i < N; i++) { scanf("%d", &VALUES[i]); }
    S[0] = VALUES[0];
    for (int i = 1; i < N; i++) { S[i] = S[i-1] + VALUES[i]; }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         ll s = (j > 0 ? DP[j-1] : 0) + ((j != i && COLORS[j] == COLORS[i]) ? S[i] - S[j] + VALUES[j] : 0);
    //         DP[i] = max(DP[i], s);
    //     }
    // }
    for (int i = 0; i < N; i++) {
        int color = COLORS[i];
        for (int c = 0; (unsigned) c < M[color].size() && M[color][c] <= i; c++) {
            int j = M[color][c];
            ll s = (j > 0 ? DP[j-1] : 0) + ((j != i) ? S[i] - S[j] + VALUES[j] : 0);
            DP[i] = max(DP[i], s);
        }
    }
    // for (int i = 0; i < N; i++) { printf("%lld%c", DP[i], (i+1==N?'\n':' ')); }
    printf("%lld\n", DP[N-1]);
}
