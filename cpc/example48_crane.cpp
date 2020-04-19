#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int STSIZE = (1 << 15) - 1;
const int MAXN = 10000+10;
const int MAXC = 10000+10;
const double M_PI = 3.141592653589793;

int N, C;
int L[MAXN];
int S[MAXC], A[MAXC];

double vx[STSIZE], vy[STSIZE];
double ang[STSIZE];

double pre[MAXN];

void init(int k, int l, int r)
{
  ang[k] = vx[k] = 0.0;
  if (r - l == 1) {
    vy[k] = L[l];
  }
  else {
    init(k*2+1, l, (l+r)/2);
    init(k*2+2, (l+r)/2, r);
    vy[k] = vy[k*2+1] + vy[k*2+2];
  }
}

void change(int s, double a, int v, int l, int r)
{
  if (s <= l) return;
  else if (s < r) {
    int chl = v*2+1, chr = v*2+2;
    int mid = (l+r)/2;
    change(s, a, chl, l, mid);
    change(s, a, chr, mid, r);
    if (s <= mid) ang[v] += a;

    double sinv = sin(ang[v]), cosv = cos(ang[v]);
    vx[v] = vx[chl] + (cosv * vx[chr] - sinv * vy[chr]);
    vy[v] = vy[chl] + (sinv * vx[chr] + cosv * vy[chr]);
  }
  else {
    ;
  }
}

void input()
{
  for (int i = 0; i < N; i++) {
    scanf("%d", L+i);
  }
  for (int i = 0; i < C; i++) {
    scanf("%d", S+i);
    scanf("%d", A+i);
  }
}

void solve()
{
  init(0, 0, N);
  for (int i = 1; i < N; i++) pre[i] = M_PI;

  for (int i = 0; i < C; i++) {
    int s = S[i];
    double a = (A[i] * M_PI) / 180.0;
    change(s, a-pre[s], 0, 0, N);
    pre[s] = a;

    printf("%.2f %.2f\n", vx[0], vy[0]);
  }
}

int main()
{
  int first = 1;
  while (scanf("%d%d", &N, &C) > 0) {
    input();
    if (first) first = 0;
    else printf("\n");
    solve();
  }
}
