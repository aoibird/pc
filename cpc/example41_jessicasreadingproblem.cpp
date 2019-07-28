#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#define MAXP 1000005
using namespace std;

int a[MAXP];
int p;
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
  set<int> total;
  for (int i = 0; i < p; i++) {
    total.insert(a[i]);
  }
  int n = total.size();

  int s = 0, t = 0, minp = p, sum = 0;
  while (1) {
    while (t < p && sum < n) {
      int x = a[t++];
      //if (cnt[a[t++]]++ == 0) {
        if (cnt[x]++ == 0) {
        sum++;
      }
    }
    if (sum < n) break;

    minp = min(minp, t-s);
    int x = a[s++];
    cnt[x] -= 1;
    //if (--cnt[a[s++]] == 0) {
      if (cnt[x] == 0) {
      sum--;
    }
  }

  printf("%d\n", minp);
}

int main()
{
  input();
  solve();
}
