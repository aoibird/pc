// POJ 3320
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define MAXP 1000005
using namespace std;

int a[MAXP];
int p;
set<int> total;
map<int, int> cnt;

void input()
{
  scanf("%d", &p);
  for (int i = 0; i < p; i++) {
    scanf("%d", &a[i]);
  }
}

void solve()
{
  for (int i = 0; i < p; i++) {
    total.insert(a[i]);
  }
  int n = total.size();

  int s = 0, t = 0, best = p;
  while (true) {
      // increase t
      while (t < p && cnt.size() < n) { cnt[a[t]] += 1; t++; }

      if (cnt.size() < n) break; // cannot contain all ideas
      best = min(best, t-s);

      // increase s
      if (s < p) { cnt[a[s]] == 1? cnt.erase(a[s]) : cnt[a[s]] -= 1; s++; }
  }

  printf("%d\n", best);
}

int main()
{
  input();
  solve();
}
