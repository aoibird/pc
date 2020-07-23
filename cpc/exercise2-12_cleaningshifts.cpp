#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 25010
#define MAXT 1000010
using namespace std;
typedef pair<int,int> P;
vector<P> v;
int N, T;

void input()
{
  scanf("%d%d", &N, &T);
  for (int i = 0; i < N; i++) {
    int e, s;
    scanf("%d%d", &s, &e);
    v.push_back(P(s, e));
  }
}

void print()
{
  for (int i = 0; i < v.size(); i++) {
    printf("%d %d\n", v[i].first, v[i].second);
  }
}

bool cmp(const P &a, const P &b) { return a.second < b.second; }

void solve()
{
    sort(v.begin(), v.end());
    if (v[0].first != 1) { printf("-1\n"); return; }

    int cnt = 1, t = 0;
    while (true) {
        int best = v[t].second, target = -1;
        for (int i = t+1; i < v.size(); i++) {
            if (v[i].first <= v[t].second + 1 && best < v[i].second) {
                best = v[i].second; target = i;
            }
        }
        //printf("target == %d\n", target);
        if (target == -1) { break; }
        cnt++;
        t = target;
    }
    if (v[t].second < T) printf("-1\n");
    else printf("%d\n", cnt);
}

int main()
{
  input();
  solve();
}
