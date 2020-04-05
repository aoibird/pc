// UVa 1471
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair<int,int> PII;
const int MAXN = 200000 + 10;
int A[MAXN];
int N;
set<PII> S;
int F[MAXN];
int G[MAXN];

void input()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
}

int solve()
{
  G[0] = 1;
  for (int i = 1; i < N; i++) {
    if (A[i-1] < A[i]) G[i] = G[i-1] + 1;
    else G[i] = 1;
  }

  F[N-1] = 1;
  for (int i = N-2; i >= 0; i--) {
    if (A[i] < A[i+1]) F[i] = F[i+1] + 1;
    else F[i] = 1;
  }

  S.clear();
  S.insert(PII(A[0], G[0]));
  int ans = 1;

  for (int i = 0; i < N; i++) {
    PII p = PII(A[i], G[i]);
    set<PII>::iterator it = S.lower_bound(p);

    bool keep = true;
    if (it != S.begin()) {
      PII last = *(--it);
      int len = F[i] + last.second;
      ans = max(ans, len);
      if (p.second <= last.second) keep = false;
    }

    if (keep) {
      S.erase(p);
      S.insert(p);
      it = S.find(p);
      it++;
      while (it != S.end() && (*it).first > p.first
             && (*it).second <= p.second) {
        S.erase(it++);
      }
    }
  }

  return ans;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    input();
    int res = solve();
    printf("%d\n", res);
  }
}
