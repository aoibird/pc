// UVa 1606
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Particle {
  int x; // [-10000, 10000]
  int y; // [-10000, 10000]
  int r; // 0 or 1
  int dx;
  int dy;
  Particle(int a=0, int b=0, int c=0, int d=0, int e=0) {
    x = a;
    y = b;
    r = c;
    dx = d;
    dy = e;
  }
};

const int MAXN = 1000;
const double TOL = 0.0001;
Particle P[MAXN+10];
int N; // [1, 1000]

bool compare_angle(Particle& a, Particle& b)
{
  if (atan2(a.y, a.x) > atan2(a.y, a.x)) return true;
  else return false;
}

int solve()
{
  int best = 0;
  for (int i = 0; i < N; i++) {
    swap(P[i], P[0]);
    for (int j = 1; j < N; j++) {
      P[j].dx = P[j].x - P[0].x;
      P[j].dy = P[j].y - P[0].y;
    }
    sort(P+1, P+N, compare_angle);
    int pos = 0;
    for (int j = 1; j < N; j++) if (P[j].dy > 0) { pos = j; break; }

    int cnt[5] = {0}; // up 0/1, down 0/1, fuzz
    for (int j = 1; j < N; j++) {
      if (P[j].dy < 0) {
        if (P[j].r == 0) cnt[0] += 1;
        else cnt[1] += 1;
      }
      else if (P[j].dy > 0) {
        if (P[j].r == 0) cnt[2] += 1;
        else cnt[3] += 1;
      }
      else cnt[4] += 1;
    }
    best = max(max(cnt[0] + cnt[3] + cnt[4], cnt[1] + cnt[2] + cnt[4]), best);

    // scan
    int up = pos;
    for (int j = 1; j < pos; j++) {
      if (P[j].dy < 0) {
        cnt[4] += 1;
        if (P[j].r == 0) cnt[2] -= 1;
        else cnt[3] -= 1;
      }
      else if (P[j].dy > 0) {
        cnt[4] += 1;
        if (P[j].r == 0) cnt[0] -= 1;
        else cnt[1] -= 1;
      }
      else ;
      double da = atan2(-P[j].y, -P[j].x) - atan2(P[up].y, P[up].x);
      if (up >= N) {
        ;
      }
      else if (da > TOL) {
        if (P[up].r == 0) { cnt[0] -= 1; cnt[2] += 1; }
        else { cnt[1] -= 1; cnt[3] += 1; }
        up += 1;
      }
      else if (da < TOL) {
        ;
      }
      else {
        if (P[up].r == 0) cnt[0] -= 1;
        else cnt[1] -= 1;
        cnt[4] += 1;
      }
    }

    best = max(max(cnt[0] + cnt[3] + cnt[4], cnt[1] + cnt[2] + cnt[4]), best);
  }

  return best;
}

int main()
{
  while (scanf("%d", &N) == 1) {
    if (N == 0) break;
    for (int i = 0; i < N; i++) scanf("%d%d%d", &P[i].x, &P[i].y, &P[i].r);
    int res = solve();
    printf("%d\n", res);
  }
}
