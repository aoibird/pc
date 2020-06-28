// UVa 242
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

const int MAXN = 10*2;
const int MAXV = 200000000;
const int INF = 10000;
vector<int> sets[MAXN];
int dp[MAXV];
int S, N;

void calc(const vector<int> &set, int &amount, int &cnt)
{
    int maxv = set[set.size()-1]*S;
    dp[0] = 0;
    for (amount = 1; amount <= maxv; amount++) {
        dp[amount] = INF;
        for (int j = 0; j < set.size();  j++) {
            int denom = set[j];
            if (amount - denom >= 0 && dp[amount - denom]+1 <= S) {
                // printf("%d(%d): %d(%d) + 1(%d)\n",
                //        dp[amount], amount,
                //        dp[amount - denom], amount - denom,
                //        denom);
                dp[amount] = min(dp[amount], dp[amount - denom] + 1);
            }

        }
        if (dp[amount] >= INF) break;
    }
    amount -= 1;
    cnt = dp[amount];
}

void solve()
{
    int maxamount = 0, maxcnt = 0, maxi = 0;
    for (int i = 0; i < N; i++) {
        int amount, cnt;
        calc(sets[i], amount, cnt);
        if (amount > maxamount ||
            (amount == maxamount && cnt > maxcnt) ||
            (amount == maxamount && cnt == maxcnt
             && sets[i][sets[i].size()-1] < sets[maxi][sets[maxi].size()-1])) {
            maxamount = amount;
            maxcnt = cnt;
            maxi = i;
        }
    }

    printf("max coverage = %3d :", maxamount);
    for (int j = 0, l = sets[maxi].size(); j < l; j++) {
        printf("%3d", sets[maxi][j]);
    }
    printf("\n");
}

int main()
{
    while (scanf("%d%d", &S, &N) == 2 && S) {
        for (int i = 0; i < N; i++) {
            sets[i].resize(0);
            int m; scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                int value; scanf("%d", &value);
                sets[i].push_back(value);
            }
        }
        solve();
    }
}
