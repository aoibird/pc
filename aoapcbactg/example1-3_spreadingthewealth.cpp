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
ll A[MAXN+10], C[MAXN+10];
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



ll solve()
{
  A[0] = 0;
  for (int i = 1; i < N; i++) A[i] = A[i-1] + A[i] - AVG;
  sort(A, A+N);

  ll mid = A[N/2];
  ll best = 0;
  for (int i = 0; i < N; i++) best += abs(mid - A[i]);

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
