// POJ 3040
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

const int MAXN = 20+10;
PII D[MAXN];
int N, C;

bool cmp(const PII &a, const PII &b)
{
    return a.first > b.first || (a.first==b.first && a.second > b.second);
}

int take(int amount)
{
    int cnt = 0;
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
            amount -= D[x].first; D[x].second -= 1; cnt++;
        }
        else if (y != -1) {
            // printf("%d(%d) ", D[y].first, amount);
            amount -= D[y].first; D[y].second -= 1; cnt++;
        }
        else break;
    }
    // printf("\n");
    if (cnt != 0) return true;
    else return false;
}

void solve()
{
    sort(D, D+N, cmp);
    int cnt = 0;
    while (take(C)) {
        cnt++;
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
