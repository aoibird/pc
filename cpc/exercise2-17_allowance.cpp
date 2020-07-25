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

const int INF = 1000000000;
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
    int cnt = 0;
    map<int,int> m;
    // printf("take ---");
    while (amount > 0) {
        int x = -1;
        for (int i = 0; i < N; i++) {
            if (D[i].first <= amount && D[i].second > 0) { x = i; break; }
        }
        int y = -1;
        for (int i = N-1; i >= 0; i--) {
            if (D[i].first > amount && D[i].second > 0) { y = i; break; }
        }
        if (x != -1) {
            // printf("%d(%d) ", D[x].first, amount);
            amount -= D[x].first; D[x].second -= 1; m[x] += 1; cnt++;
        }
        else if (y != -1) {
            // printf("%d(%d) ", D[y].first, amount);
            amount -= D[y].first; D[y].second -= 1; m[y] += 1; cnt++;
        }
        else break;
    }
    if (cnt == 0) return 0;
    int mi = INF;
    for (map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
        PII pair = *it; int index = pair.first; int cnt = pair.second;
        // printf("[%d %d %d]", D[index].second, cnt, D[index].second / cnt);
        mi = min(mi, D[index].second / cnt);
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
    printf("%d\n", cnt);
}

int main()
{
    scanf("%d%d", &N, &C);
    for (int i = 0; i < N; i++) {
        int v, b; scanf("%d%d", &v, &b);
        D[i] = PII(v, b);
    }
    solve();
}
