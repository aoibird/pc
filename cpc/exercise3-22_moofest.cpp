// POJ 1990 MooFest
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

const int MAXN = 20000+5; // N ~ [1, 20000]
const int MAXV = 20000+5; // vol ~ [1, 20000]
PII cows[MAXN];
int N;
ll BITD[MAXV];
ll BITC[MAXV];

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


ll sum(ll *bit, int i)
{
    ll s = 0; for (; i > 0; i-=i&-i) { s += bit[i]; } return s;
}

void add(ll *bit, int n, int i, ll x)
{
    for ( ; i <= n; i+=i&-i) bit[i] += x;
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        int maxvol = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d%d",&cows[i].second,&cows[i].first);
            maxvol = max(maxvol, cows[i].second);
        }

        sort(cows, cows+N);

        ll s = 0;
        memset(BITD, 0, sizeof(BITD));
        memset(BITC, 0, sizeof(BITC));
        for (int i = 0; i < N; i++) {
            int pos = cows[i].first, vol = cows[i].second;
            s += vol * (sum(BITC, vol) * pos - sum(BITD, vol));

            add(BITD, maxvol, vol, pos);
            add(BITC, maxvol, vol, 1);
        }
        memset(BITD, 0, sizeof(BITD));
        memset(BITC, 0, sizeof(BITC));
        for (int i = N-1; i >= 0; i--) {
            int pos = cows[i].first, vol = cows[i].second;
            s += vol * -(sum(BITC, vol-1) * pos - sum(BITD, vol-1));

            add(BITD, maxvol, vol, pos);
            add(BITC, maxvol, vol, 1);
        }
        printf("%lld\n", s);
    }
}
