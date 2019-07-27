#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

struct money {
  int dollars;
  int cents;
  money(int x=0, int y=0) {
    dollars = x;
    cents = y;
  }
  money operator + (const money &x) {
    int t1 = dollars + x.dollars;
    int t2 = cents + x.cents;
    if (t2 >= 100) { t2 -= 100; t1 += 1; }
    return money(t1, t2);
  }
  money operator - (const money &x) {
    int t1 = dollars - x.dollars;
    int t2 = cents - x.cents;
    if (t2 < 0) { t2 += 100; t1 -= 1; }
    return money(t1, t2);
  }
  money operator / (const int &d) {
    int t1 = dollars / d;
    int r = dollars % d;
    int t2 = (cents + r * 100) / d;
    return money(t1, t2);
  }
  bool operator > (const money &x) {
    if (dollars > x.dollars) return true;
    else if (dollars == x.dollars && cents > x.cents)
      return true;
    else return false;
  }
  bool operator < (const money &x) {
    return !(money(dollars, cents) > x);
  }
};

const int MAXN = 1005;
money A[MAXN]; // Ai < 10000.00
//double A[MAXN];
int N; // < 1000
money S;
money AVG;

bool compare(money x, money y)
{
  if (x.dollars < y.dollars) return true;
  else if (x.cents < y.cents) return true;
  else return false;
}


void input()
{
  S = money(0, 0);
  for (int i  = 0; i < N; i++) {
    int x, y;
    scanf("%d.%d", &x, &y);
    A[i] = money(x, y);
    S = S + A[i];
  }
  // printf("%d.%d\n", S.dollars, S.cents);
  AVG = S / N;
}

void trace()
{
  for (int i = 0; i < N; i++) {
    printf("%d.%d ", A[i].dollars, A[i].cents);
  }
  printf("\n");
}

void solve()
{
  // sort
  sort(A, A+N, compare);
  // greatest to smallest
  money sum = money(0, 0);
  // printf("%d.%d\n", AVG.dollars, AVG.cents);
  // trace();
  for (int i = 0; i < N; i++) {
    // printf("%d.%d < %d.%d ? %d\n",
    //        A[i].dollars, A[i].cents,
    //        AVG.dollars, AVG.cents,
    //        A[i] < AVG);
    if (!(A[i] < AVG)) break;
    money diff = AVG - A[i];
    // printf("%d.%d =  %d.%d - %d.%d\n",
    //        diff.dollars, diff.cents,
    //        AVG.dollars, AVG.cents,
    //        A[i].dollars, A[i].cents);
    sum = sum + diff;
    // A[i] = AVG;

    // trace();
  }

  printf("$%d.%02d\n", sum.dollars, sum.cents);
}



int main()
{
  // for each test case run input, solve

  while (scanf("%d", &N) && N) {
    input();
    solve();
  }
}
