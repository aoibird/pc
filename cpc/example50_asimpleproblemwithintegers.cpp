// POJ 3468 A Simple Problem with Integers
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

const int MAXQ = 1e5+5;
const int MAXN = 1e5+5;
int A[MAXN];
char T[MAXQ];
int L[MAXQ], R[MAXQ], X[MAXQ];
int N, Q;
ll BIT0[MAXN], BIT1[MAXN];

ll sum(ll *b, int i)
{
    ll s = 0;
    for ( ; i > 0; i -= i&-i) s += b[i];
    return s;
}

void add(ll *b, int i, int v)
{
    for ( ; i <= N; i += i&-i) b[i] += v;
}

void solve()
{
    for (int i = 1; i <= N; i++) add(BIT0, i, A[i]);

    for (int i = 0; i < Q; i++) {
        if (T[i] == 'C') {
            add(BIT0, L[i], -X[i]*(L[i]-1));
            add(BIT1, L[i], X[i]);
            add(BIT0, R[i] + 1, X[i]*R[i]);
            add(BIT1, R[i] + 1, -X[i]);
        }
        else if (T[i] == 'Q') {
            ll res = 0;
            res += sum(BIT0, R[i]) + sum(BIT1, R[i])*R[i];
            res -= sum(BIT0, L[i]-1) + sum(BIT1, L[i]-1)*(L[i]-1);
            printf("%lld\n", res);
        }
        else ;
    }
}

int main()
{
    while (scanf("%d%d", &N, &Q) == 2 && N) {
        for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
        int ch;
        while ((ch = getchar()) != EOF && ch != '\n') ;
        for (int i = 0; i < Q; i++) {
            T[i] = getchar();
            if (T[i] == 'Q') scanf("%d%d", &L[i], &R[i]);
            else if (T[i] == 'C') scanf("%d%d%d", &L[i], &R[i], &X[i]);
            else ;
            while ((ch = getchar()) != EOF && ch != '\n') ;
        }

        solve();
    }
}
