// POJ 2400
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 15+5;
int MP[MAXN][MAXN]; // men preferences
int MO[MAXN][MAXN];
int WO[MAXN][MAXN]; // women orders
int NEXT[MAXN];
int FH[MAXN], FW[MAXN]; // future husband, future wife
queue<int> q;
int N;

void engage(int man, int woman)
{
  int m = FH[woman];
  if (m) {
    FW[m] = 0;
    q.push(m);
  }
  FW[man] = woman;
  FH[woman] = man;
}

void solve()
{
  while (!q.empty()) {
    int man = q.front(); q.pop();
    int woman = MP[man][NEXT[man]++];
    if (!FH[woman]) engage(man, woman);
    else if (WO[woman][man] < WO[woman][FH[woman]]) engage(man, woman);
    else q.push(man);
  }
}

void input()
{
  scanf("%d", &N);
  //printf("N = %d\n", N);
  // man
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int x;
      scanf("%d", &x);
      MP[i][j] = x;
      MO[i][x] = j;

      //printf("%d ", x);
    }
    NEXT[i] = 1;
    FW[i] = 0;
    q.push(i);
    //printf("\n");
  }
  //printf("\n");
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int x; scanf("%d", &x);
      WO[i][x] = j;

      //printf("%d ", x);
    }
    FH[i] = 0;

    //printf("\n");
  }
}

void init()
{
  while (!q.empty()) q.pop();
}

void output(int t)
{
  int best_pair = 1, best_d = MO[1][FW[1]] - 1, sum = 0;
  for (int i = 1; i <= N; i++) {
    int dw = WO[i][FH[i]] - 1;
    int dp = MO[i][FW[i]] - 1;
    //printf("%d:%d:%d %d:%d:%d\n", i, FH[i], dw, i, FW[i], dp);
    sum += dw + dp;
    if (dp < best_d) { best_pair = i; best_d = dp; }
  }
  printf("Data Set %d, Best average difference: %.6f\n",
         t+1, (double)sum/((double)2*N));
  printf("Best Pairing %d\n", best_pair);
  for (int i = 1; i <= N; i++) {
    printf("Supervisor %d with Employee %d\n", i, FW[i]);
  }
}

int main()
{
  int T; scanf("%d", &T);
  bool first = true;
  for (int i = 0; i < T; i++) {
    if (first) first = false;
    else printf("\n");
    init();
    input();
    solve();
    output(i);
  }
}
