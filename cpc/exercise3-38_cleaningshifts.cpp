// POJ 3171 Cleaning Shifts
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

struct Cow {
    int left, right, cost;
    Cow(int l=0, int r=0, int c=0) { left=l; right=r; cost=c; }
};

const int INF = 0x3f3f3f3f;
const int MAXN = 10000+5;
const int MAXE = 86399+11;
const int MAXE2 = 1 << 17;
Cow A[MAXN];
int N, M, E;
int dp[MAXE];
int n, seg[2 * MAXE2 - 1];

void init(int N)
{
    n = 1; while (n < N) n *= 2;
    for (int i = 0; i < 2*n-1; i++) seg[i] = INF;
}

void update(int k, int a)
{
    k += n - 1; seg[k] = a;
    while (k > 0) { k = (k-1)/2; seg[k] = min(seg[k*2+1], seg[k*2+2]); }
}

int query(int a, int b, int k, int l, int r)
{
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return seg[k];
    else return min(query(a, b, k*2+1, l, (l+r)/2), query(a, b, k*2+2, (l+r)/2, r));
}

bool cmp(const Cow &a, const Cow &b)
{
    return a.left < b.left || (a.left==b.left && a.right < b.right);
}

int main()
{
    while (scanf("%d%d%d", &N, &M, &E) == 3) {
        for (int i = 0; i < N; i++) scanf("%d%d%d", &A[i].left, &A[i].right, &A[i].cost);

        sort(A, A+N, cmp);
        memset(dp, 0x3f, sizeof(dp));
        init(E+1);
        for (int i = 0; i < N; i++) {
            int l = A[i].left, r = A[i].right, c = A[i].cost;
            if (l == M) { dp[r] = c; update(r, c); }
            else { dp[r] = min(dp[r], query(l-1, r+1, 0, 0, n) + c); update(r, dp[r]); }
        }
        printf("%d\n", dp[E]<INF?dp[E]:-1);
    }
}
