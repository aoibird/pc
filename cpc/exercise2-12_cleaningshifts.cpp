#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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

void solve()
{
  sort(v.begin(), v.end());
  print();

  int curr = 1;
  int cnt = 0, ok = 1;
  int i = 0;
  while (curr < T) {

    if (v[i].first > curr) { ok = 0; break; }
    //printf("i = %d curr = %d\n", i, curr);
    while (i < v.size() && v[i].first <= curr) i++;
    if (i == v.size() && v[i-1].second < T) { ok = 0; break; }
    //if (v[i].first > curr) { ok = 0; break; }
    //i--;
    //printf("i = %d\n", i);

    curr = v[i-1].second;
    cnt++;
    //printf("curr %d\n", curr);
  }

  if (ok) printf("%d\n", cnt);
  else printf("-1\n");
}

int main()
{
  input();
  solve();
}
