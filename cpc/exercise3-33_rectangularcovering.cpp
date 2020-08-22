// POJ 2836 Rectangular Covering
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

const int INF = 0x3f3f3f3f;
const int MAXN = 15;
PII A[MAXN];
int N;
int dp[1 << MAXN];

int get_area(int set)
{
    vector<int> s;
    for (int i = 0; set; i++, set>>=1) { if (set&1) s.push_back(i); }
    if (s.size() < 2) return INF;

    int t = s[0];
    int fx = A[t].first, tx = A[t].first, fy = A[t].second, ty = A[t].second;
    for (int i = 0; i < s.size(); i++) {
        int t = s[i];
        fx = min(fx, A[t].first); tx = max(tx, A[t].first);
        fy = min(fy, A[t].second); ty = max(ty, A[t].second);
    }
    if (ty - fy == 0) return 1 * (tx - fx);
    if (tx - fx == 0) return (ty - fy) * 1;
    return (ty - fy) * (tx - fx);
}


void solve()
{
    for (int s = 0; s < (1<<N); s++) dp[s] = get_area(s);
    for (int s = 1; s < (1<<N); s++) {
        for (int t = 1; t < s; t++) {
            dp[t|s] = min(dp[t|s], dp[t] + dp[s]);
        }
    }
    printf("%d\n", dp[(1<<N)-1]);
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%d%d", &A[i].first, &A[i].second);

        fill(dp, dp+(1<<N), INF);
        solve();
    }
}
