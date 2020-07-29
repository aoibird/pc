// POJ 2392
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

struct Block {
    int h, a, c;
    Block(int hi=0, int ai=0, int ci=0) { hi=h; ai=a; ci=c; }
};

const int MAXA = 40000+10;
const int MAXK = 400+10;
Block B[MAXK];
int dp[MAXA];
int K, MA;

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}

bool cmp(const Block &a, const Block &b) { return a.a < b.a; }

void solve()
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j <= B[i].a; j++) {
            if (dp[j] >= 0) { dp[j] = B[i].c; }
            else if (j < B[i].h || dp[j-B[i].h] <= 0) { dp[j] = -1; }
            else { dp[j] = dp[j-B[i].h] - 1; }
        }
        // print_array(dp, MA+1);
    }
    int m = 0;
    for (int i = 0; i <= MA; i++) if (dp[i] >= 0) m = max(m, i);

    printf("%d\n", m);
}

int main()
{
    while (scanf("%d", &K) == 1) {
        MA = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < K; i++) {
            scanf("%d%d%d", &B[i].h, &B[i].a, &B[i].c);
            MA = max(MA, B[i].a);
        }
        sort(B, B+K, cmp);

        solve();
    }
}

