// POJ 1065
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

const int MAXN = 5000+10;
PII S[MAXN];
int vis[MAXN];
int N;

void print_array(PII *a, int n)
{
    for (int i = 0; i < n; i++) printf("(%d,%d)%c", a[i].first, a[i].second, i==n-1?'\n':' ');
}

bool cmp(const PII &a, const PII &b)
{
    return (a.first < b.first) || (a.first==b.first && a.second < b.second);
}

void solve()
{
    memset(vis, 0, sizeof(vis));
    sort(S, S+N, cmp);
    //print_array(S, N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        int wb = S[i].second;
        for (int j = 0; j < N; j++) {
            int w = S[j].second;
            if (!vis[j] && w >= wb) { vis[j] = 1; wb = w; }
        }
        cnt++;
    }
    printf("%d\n", cnt);
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int l, w; scanf("%d%d", &l, &w);
            S[i].first = l; S[i].second = w;
        }

        solve();
    }
}
