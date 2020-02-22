// POJ 3276
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5000+10;
int A[MAXN];
int N;
int K;
int M;
int F[MAXN];

void input()
{
  scanf("%d", &N); getchar();
  for (int i = 0; i < N; i++) {
    int ch = getchar(); getchar();
    if (ch == 'B') A[i] = 0;
    else A[i] = 1;
  }
}

int calc(int k)
{
  memset(F, 0, sizeof(F));
  int cnt = 0;
  int sum = 0;
  int t = 0;
  for (int i = 0; i < N; i++) {
    if (F[t] == 1) cnt -= 1;		    // remove
    F[t] = ((cnt + A[i]) % 2 == 0) ? 1 : 0; // flip?
    if (F[t] == 1 && i >= N - k + 1) return N;
    cnt += F[t];
    sum += F[t];
    t = (t + 1) % k;
  }
  return sum;
}

void solve()
{
  K = 1;
  M = N;
  for (int k = 1; k <= N; k++) {
    int m = calc(k);
    if (m < M) { M = m; K = k; }
  }
  printf("%d %d\n", M, K);
}

int main()
{
  input();
  solve();
}
