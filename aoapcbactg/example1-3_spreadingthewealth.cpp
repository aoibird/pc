// UVa 11300
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


typedef long long ll;
const int MAXN = 1000000;
ll A[MAXN+10];
int N; // [1, 1_000_000]
ll SUM, AVG;

void input()
{
  SUM = 0;
  for (int i = 0; i < N; i++) {
    scanf("%lld", A+i);
    SUM += A[i];
  }
  AVG = SUM / N;
}

ll get(int dist, ll& dst, ll& src)
{
  ll need = AVG - dst;
  ll rest = src - AVG;
  if (need <= 0 || rest <= 0) return 0;

  if (need > rest) {
    src -= rest;
    dst += rest;
    return rest * dist;
  }
  else {
    src -= need;
    dst += need;
    return need * dist;
  }
}

ll solve()
{
  ll best = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] >= AVG) continue;

    // A[i] < AVG
    for (int j = 1; j <= N/2; j++) {
      if (A[i] >= AVG) break;

      best += get(j, A[i], A[(i+j)%N]);
      best += get(j, A[i], A[(i-j+N)%N]);
    }
  }

  return best;
}

int main()
{
  while (scanf("%d", &N) == 1) {
    input();
    ll res = solve();
    printf("%lld\n", res);
  }
}
