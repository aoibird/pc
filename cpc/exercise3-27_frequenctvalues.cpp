// POJ 3368 Frequenct values
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

const int MAXN = 100000+5;
PII A[MAXN];
int P[MAXN];
int N, Q, NU;
int n, seg[2 * MAXN-1];

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}

void print_pair_array(PII *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("(%d %d)%c", a[i].first, a[i].second, i==n-1?'\n':' ');
}

void init(int N)
{
    n = 1; while (n < N) n *= 2;
    for (int i = 0; i < 2*n-1; i++) seg[i] = INT_MIN;
}

void update(int k, int a)
{
    k += n-1; seg[k] = a;
    while (k > 0) { k =(k-1)/2; seg[k] = max(seg[k*2+1], seg[k*2+2]); }
}

int query(int a, int b, int k, int l, int r) // Range Maximum Query
{
    if (r <= a || b <= l) return INT_MIN;
    if (a <= l && r <= b) return seg[k];
    else {
        int vl = query(a, b, k*2+1, l, (l+r)/2);
        int vr = query(a, b, k*2+2, (l+r)/2, r);
        return max(vl, vr);
    }
}

int main()
{
    while (scanf("%d%d", &N, &Q) == 2 && N) {
        NU = 0;
        memset(A, 0, sizeof(A));
        for (int i = 1; i <= N; i++) {
            int a; scanf("%d", &a);
            if (NU != 0 && a == A[NU-1].first) A[NU-1].second += 1;
            else A[NU++] = PII(a, 1);
        }

        init(NU);
        for (int i = 0; i < NU; i++) update(i, A[i].second);
        P[0] = 1; for (int i = 1; i < NU; i++) P[i] = P[i-1]+A[i-1].second;

        // print_pair_array(A, NU);
        // print_array(P, NU);
        // print_array(seg, 2*n-1);

        for (int i = 0; i < Q; i++) {
            int l, r; scanf("%d%d", &l, &r);
            int lp = upper_bound(P, P+NU, l)-P-1;
            int rp = upper_bound(P, P+NU, r)-P-1;
            int lv = 0, rv = 0, mv = 0;
            if (lp == rp) mv = r-l+1;
            else  {
                if (l != P[lp]) { lv = P[lp]+A[lp].second-l; lp++; }
                if (r != P[rp] + A[rp].second-1) { rv = r-P[rp]+1; rp--; }
                if (lp <= rp) { mv = query(lp, rp+1, 0, 0, n); }
            }

            // printf("%d %d %d\n", lv, mv, rv);
            printf("%d\n", max(mv, max(lv, rv)));
        }
    }
}
