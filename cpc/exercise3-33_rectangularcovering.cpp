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
    dp[0] = INF;
    for (int i = 0; i < N; i++) dp[1<<i] = INF;

    for (int k = 2; k <= N; k++) {
        for (int set = (1<<k)-1; set < (1<<N); ) {
            dp[set] = get_area(set);

            for (int s1=(set-1)&set; s1; s1=(s1-1)&set) {
                for (int s2=(set-1)&set; s2; s2=(s2-1)&set) {
                    if ((s1|s2)==set) dp[set] = min(dp[set], dp[s1] + dp[s2]);
                }
            }

            int x = set & -set, y = set + x;
            set = ((set & ~y) / x >> 1) | y;
        }
    }
    printf("%d\n", dp[(1<<N)-1]);
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%d%d", &A[i].first, &A[i].second);

        memset(dp, 0, sizeof(dp));
        solve();
    }
}
