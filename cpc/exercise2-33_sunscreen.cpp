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

const int MAXC = 2500+10;
const int MAXL = 2500+10;
PII CO[MAXC];
PII LO[MAXL];
int C, L;
priority_queue<int, vector<int>, greater<int> > PQ;

void print_array(PII a[MAXL], int n)
{
    for (int i = 0; i < n; i++) printf("(%d,%d)%c", a[i].first, a[i].second, i==n-1?'\n':' ');
}


void solve()
{
    sort(CO, CO+C);
    sort(LO, LO+L);
    int t = 0, cnt = 0;
    for (int i = 0; i < L; i++) {
        while (t < C && CO[t].first <= LO[i].first) { PQ.push(CO[t].second); t++; }
        while (!PQ.empty() && LO[i].second > 0) {
            int maxspf = PQ.top(); PQ.pop();
            if (maxspf >= LO[i].first) { cnt++; LO[i].second--; }
        }
    }
    // print_array(LO, L);
    printf("%d\n", cnt);
}

int main()
{
    while (scanf("%d%d", &C, &L) == 2) {
        while (!PQ.empty()) PQ.pop();
        memset(LO, 0, sizeof(LO));
        for (int i = 0; i < C; i++) { scanf("%d%d", &CO[i].first, &CO[i].second); }
        for (int i = 0; i < L; i++) { scanf("%d%d", &LO[i].first, &LO[i].second); }
        solve();
    }
}
