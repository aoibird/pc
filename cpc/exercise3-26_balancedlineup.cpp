// POJ 3264
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50000+10;
const int MAXNT = 65536+10;
const int MAXH = 2000000;
const int MINH = 0;
int A[MAXN];
int T[MAXNT]; // tallest
int S[MAXNT]; // shortest
int N;
int Q;

void init(int t[MAXNT], bool tallest)
{
  int nt = 1;
  while (nt < N) nt *= 2;

  int full = nt*2-2;
  // printf("%d\n", full);
  for (int i = full; i >= 0; i--) {
    if (2*i+1 <= full && 2*i+2 <= full) {
      t[i] = (tallest) ? max(t[2*i+1], t[2*i+2]) :
        min(t[2*i+1], t[2*i+2]);
    }
    else {
      if (nt - (full-i) <= N) t[i] = A[nt - (full-i)];
      else t[i] = (tallest) ? MINH : MAXH;
    }
  }
  // for (int i = 0; i <= full; i++)
  //   printf("%d%c", t[i], i==full?'\n':' ');
}

int query(int t[MAXNT], bool tallest, int a, int b,
          int k, int l, int r)
{
  if (r <= a || b <= l) {
    return (tallest) ? MINH : MAXH;
  }

  if (a <= l && r <= b) {
    return t[k];
  }
  else {
    int vl = query(t, tallest, a, b, k*2+1, l, (l+r)/2);
    int vr = query(t, tallest, a, b, k*2+2, (l+r)/2, r);
    return (tallest) ? max(vl, vr) : min(vl, vr);
  }
}


int main()
{
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

  init(T, true);
  init(S, false);

  for (int i = 0; i < Q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    int t = query(T, true, a, b+1, 0, 1, N+1);
    int s = query(S, false, a, b+1, 0, 1, N+1);
    printf("%d\n", t-s);
  }
}
