// POJ 3040
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int INF = 2000000000;
const int MAXN = 20+10;
PII D[MAXN];
int N, C;

void print_d()
{
    for (int i = 0; i < N; i++) printf("(%d,%d)%c", D[i].first, D[i].second,
                                       i==N-1?'\n':' ');
}

bool cmp(const PII &a, const PII &b)
{
    return a.first > b.first || (a.first==b.first && a.second > b.second);
}

int take(int amount)
{
    map<int,int> m;
    // printf("take ---");
    while (amount > 0) {
        bool found = false;
        for (int i = 0; i < N; i++) {
            if (D[i].second > 0 && amount / D[i].first > 0
                //&& amount / D[i].first <= D[i].second
                ) {
                int c = (amount / D[i].first < D[i].second) ?
                    amount / D[i].first : D[i].second;
                // printf("(%d * %d)", D[i].first, c);
                m[i] += c;
                D[i].second -= c;
                amount -= D[i].first * c;
                found = true;
            }
        }
        if (!found) break;
    }
    // printf("(rest amount = %d)", amount);
    if (amount > 0) { // rest
        bool found = false;
        for (int i = N-1; i >= 0; i--) {
            if (D[i].second <= 0 || amount <= 0) continue;
            if (amount < D[i].first || amount / D[i].first <= D[i].second) {
                int c = (amount / D[i].first > 0
                         && amount <= D[i].second * D[i].first) ?
                    amount / D[i].first : 1;
                // printf("(%d %d)", D[i].first, c);
                m[i] += c;
                D[i].second -= c;
                amount -= D[i].first * c;
                found = true;
            }
        }
        if (!found) return 0;
    }

    int mi = INF;
    for (map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
        PII pair = *it; int index = pair.first; int cnt = pair.second;
        // printf("[%d %d %d]", D[index].second, cnt, D[index].second / cnt);
        if (cnt > 0) mi = min(mi, D[index].second / cnt);
    }
    for (map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
         PII pair = *it; int index = pair.first; int cnt = pair.second;
         D[index].second -= (mi * cnt);
    }
    // printf(" * %d\n", mi+1);
    // print_d();
    return mi+1;
}


void solve()
{
    sort(D, D+N, cmp);
    int cnt = 0, c = 0;
    while ((c = take(C)) != 0) {
        cnt += c;
    }
    // printf("\n");
    printf("%d\n", cnt);
}

int main()
{
    while (scanf("%d%d", &N, &C) == 2) {
        if (N == 0 && C == 0) break;
        memset(D, 0, sizeof(D));
        for (int i = 0; i < N; i++) {
            int v, b; scanf("%d%d", &v, &b);
            D[i] = PII(v, b);
        }
        solve();
    }
}
