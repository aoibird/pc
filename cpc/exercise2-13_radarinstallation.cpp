#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXN 1010
using namespace std;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
PII PS[MAXN];
PDD R[MAXN];
int N, D;

void input()
{
  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    PS[i] = PII(x, y);
  }
}

void print()
{
  for (int i = 0; i < N; i++) {
    printf("%d %d %.6f %.6f\n", PS[i].first, PS[i].second, R[i].first, R[i].second);
  }
}

/*
void solve()
{
  sort(PS, PS+N);
  //print();

  int cnt = 0;
  int curr = PS[0].first;
  int ok = 1;
  int i = 0;
  while (i < N) {
    int x = PS[i].first;
    int y = PS[i].second;
    if (D <= 0) { ok = 0; break; }
    if (y <= 0) { ok = 0; break; }
    if (y > D) { ok = 0; break; }
    if (i == N) break;

    while (((curr-x)*(curr-x) + y * y) <= (D*D)) curr++;
    curr--;
    //printf("curr %d %d %d\n", curr, (curr+1-x)*(curr+1-x) + y * y, D*D);
    while (i < N && ((curr-PS[i].first)*(curr-PS[i].first) +
                     PS[i].second*PS[i].second <= D*D)) {
      i++;
    }
    printf("(%d) %d\n", curr, i);
    cnt++;

    curr = PS[i].first;
  }

  if (ok) printf("%d\n", cnt);
  else printf("-1\n");
}
*/

void solve()
{
  int ok = 1;
  for (int i = 0; i < N; i++) {
    if (PS[i].second > D || PS[i].second < 0 || D < 0) {
      ok = 0;
      break;
    }
    else {
      double t = sqrt((D*(double)D)-(PS[i].second*(double)PS[i].second));
      R[i] = PDD(PS[i].first-t, PS[i].first+t);
    }
  }
  if (!ok) {
    printf("-1\n");
    return;
  }

  sort(R, R+N);
  //print();

  /*
  int l = R[0].first, r=  R[0].second;
  int i = 0;
  int cnt = 0;
  while (1) {
    while (i < N && R[i].first <= r) {
      l = R[i].first;
      if (R[i].second < r) r = R[i].second;
      i++;
    }
    //printf("l r i %d %d %d\n", l, r, i);

    cnt++;
    l = R[i].first;
    r = R[i].second;

    if (i == N) break;
    i++;
  }
  */

  /*
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int r = R[i].second;
    cnt++;
    for (int j = i+1; j < N; j++) {
      if (R[j].first <= r) {
        i++;
        if (R[j].second < r) r = R[j].second;
      }
      else {
        break;
      }
    }
  }
  */
  int cnt = 0, i = 0;
  int r = R[i].second;
  while (i < N) {
    while (i < N && R[i].first <= r) {
      if (R[i].second < r) r = R[i].second;
      i++;
    }

    cnt++;
    r = R[i].second;
  }

  printf("%d\n", cnt);
}

int main()
{
  int T = 1;
  while(scanf("%d%d", &N, &D) == 2 && !(N == 0 && D == 0)) {
    input();
    printf("Case %d: ", T);
    solve();

    T++;
  }
}
