// POJ 3614
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

// const int MAXC = 2500+10;
const int MAXL = 2500+10;
PII LO[MAXL];
int C, L;
priority_queue<PII, vector<PII>, greater<PII> > PQ;

void print_array(PII a[MAXL], int n)
{
    for (int i = 0; i < n; i++) printf("(%d,%d)%c", a[i].first, a[i].second, i==n-1?'\n':' ');
}


void solve()
{
    sort(LO, LO+L);
    int i = 0, cnt = 0;
    while (!PQ.empty() && i < L) {
        PII p = PQ.top(); PQ.pop();
        int lower = p.second, upper = p.first;
        int &spf = LO[i].second, &cover = LO[i].first;
        if (spf != 0 && lower <= cover && cover <= upper) {
            spf -= 1; cnt++;
        }

        if (spf == 0) { i++; }
    }
    // print_array(LO, L);
    printf("%d\n", cnt);
}

int main()
{
    while (scanf("%d%d", &C, &L) == 2) {
        while (!PQ.empty()) PQ.pop();
        memset(LO, 0, sizeof(LO));
        for (int i = 0; i < C; i++) { int l, u; scanf("%d%d", &l, &u); PQ.push(PII(u, l)); }
        for (int i = 0; i < L; i++) { scanf("%d%d", &LO[i].first, &LO[i].second); }
        solve();
    }
}
