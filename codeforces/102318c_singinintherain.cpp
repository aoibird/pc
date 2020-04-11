#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
//const int MAXT = 1000000000+10;
const int MAXS = 1000+10;
int SEQ[MAXS];
int T, S;

ll solve()
{
  ll res = 0;
  for (int i = 0; i < S - 1; i++) {
    int curr = (SEQ[i] == T) ? 1 : SEQ[i] + 1;
    int diff = curr - SEQ[i+1];
    diff = (diff >= 0)? diff : -diff;
    diff = min(diff, T - diff);
    res += diff;
  }
  return res;
}

int main()
{
  int TC; scanf("%d\n", &TC);
  for (int tc = 0; tc < TC; tc++) {
    scanf("%d%d", &T, &S);
    for (int i = 0; i < S; i++) scanf("%d", &SEQ[i]);
    ll res = solve();
    printf("%lld\n", res);
  }
}
