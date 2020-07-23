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
    sort(v.begin(), v.end(), cmp);
    int cnt = 0, time = 0, sel = -1;
    while (sel < ((int)v.size())-1) {
        for (sel = v.size()-1; sel >= 0; sel--) {
            if (v[sel].first <= time + 1 && v[sel].second > time) break;
        }
        if (sel == -1) { cnt = -1; break; }
        else { time = v[sel].second; cnt++; }
    }
    if (v[sel].second != T) cnt = -1;
    printf("%d\n", cnt);
}

int main()
{
  input();
  solve();
}
