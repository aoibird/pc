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

void solve()
{
    memset(vis, 0, sizeof(vis));
    sort(S, S+N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        for (int j = 0; j < N; j++) {
            int l = S[j].first, w = S[j].second;
            if (!vis[j] && l >= S[i].first && w >= S[i].second) { vis[j] = 1; }
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
