// POJ 3259
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;
const int MAXN = 500+10;
int G[MAXN][MAXN];
int N; // [1, 500]
int M; // [1, 2500]
int W; // [1, 200]

void print_g()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }
}

void solve()
{
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

void output()
{
  for (int i = 0; i < N; i++) {
    if (G[i][i] < 0) { printf("YES\n"); return; }
  }
  printf("NO\n");
}

void input()
{
  scanf("%d%d%d", &N, &M, &W);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) G[i][j] = 0;
      else G[i][j] = INF;
    }
  }
  for (int i = 0; i < M; i++) {
    int s, e, t; scanf("%d%d%d", &s, &e, &t);
    s -= 1; e -= 1;
    G[s][e] = t;
    G[e][s] = t;
  }
  for (int i = 0; i < W; i++) {
    int s, e, t; scanf("%d%d%d", &s, &e, &t);
    s -= 1; e -= 1;
    G[s][e] = -t;
  }
}

int main()
{
  int T; scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    input();
    //print_g();
    solve();
    //print_g();
    output();
  }
}
