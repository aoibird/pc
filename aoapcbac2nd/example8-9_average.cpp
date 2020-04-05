// UVa 1451
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> PII;
const int MAXN = 100000 + 10;
int A[MAXN];
int N; // [1, 100000]
int L; // [1, 1000]
int S[MAXN];
int TS[MAXN];

void input()
{
  scanf("%d%d", &N, &L); getchar();
  char ch;
  for (int i = 1; i <= N; i++) { scanf("%c", &ch); A[i] = ch-'0'; }
}

int slope_diff(int x1, int x2, int x3, int x4)
{
  return (S[x2]-S[x1-1])*(x4-x3+1) - (S[x4]-S[x3-1])*(x2-x1+1);
}



void solve()
{
  int l = 1, r = L;

  S[0] = 0;
  for (int i = 1; i <= N; i++) S[i] = S[i-1] + A[i];

  int i = 0, j = 0;
  for (int t = L; t <= N; t++) {
    while (j-i>1 && slope_diff(TS[j-2], t-L, TS[j-1], t-L) >= 0) j--;
    TS[j++] = t-L+1;

    while (j-i>1 && slope_diff(TS[i], t, TS[i+1], t) <= 0) i++;

    int c = slope_diff(TS[i], t, l, r);
    if (c > 0 || (c == 0 && (t - TS[i] < r - l))) {
      l = TS[i];
      r = t;
    }
  }

  printf("%d %d\n", l, r);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    input();
    solve();
  }
  return 0;
}
