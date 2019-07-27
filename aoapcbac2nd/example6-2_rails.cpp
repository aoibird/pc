#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

vector<int> v;
queue<int> w;
int N;

int input()
{
  v.resize(0);
  int x;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &x);
    if (x == 0) break;

    v.push_back(x);
    w.push(i);
  }

  if (v.size() == 0) return 0;
  else return 1;
}

void trace(stack<int>& s)
{
  printf("queue front: %d\n", (w.empty() ? -1 : w.front()));
  int si = (s.empty()) ? 0 : s.size();
  printf("stack: %d (%d)\n", (s.empty() ? 0: s.top()), si);
  for (int i = 0; i < N; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void solve()
{
  if (v.size() == 1) return;
  stack<int> s;


  for (int i = 0; i < N; i++) {
    while (!w.empty() && v[i] >= w.front()) {
      int x = w.front(); w.pop();
      s.push(x);
    }

    if (!s.empty()) {
      if (v[i] == s.top()) s.pop();
      else break;
    }

    //trace(s);
  }

  if (s.empty()) printf("Yes\n");
  else printf("No\n");
}

int main()
{
  while (scanf("%d", &N) && N) {
    while (1) {
      int ok = input();
      if (!ok) break;
      solve();
    }
    printf("\n");
  }
}
