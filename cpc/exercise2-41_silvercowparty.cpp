// POJ 3268
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// struct Edge {
//   int from, to, cost;
//   Edge (int f=0, int t=0, int c=0) { from=f; to=t; cost=c; }
// };
const int INF = 200000000;
const int MAXN = 1000+10;
//const int MAXM = 100000+10;
//Edge ES[MAXM];
//int DTO[MAXN];
//int DBACK[MAXN];
int G[MAXN][MAXN];
int N; // [1, 1000]
int M; // [1, 100000]
int X;

void print()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) printf("%d ", G[i][j]);
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
  int m = 0;
  for (int i = 0; i < N; i++) {
    m = max(m, G[i][X] + G[X][i]);
  }
  printf("%d\n", m);
}

void input()
{
  scanf("%d%d%d", &N, &M, &X);
  X -= 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) G[i][j] = 0;
      else G[i][j] = INF;
    }
  }
  for (int i = 0; i < M; i++) {
    int from, to, cost;
    scanf("%d%d%d", &from, &to, &cost);
    G[from-1][to-1] = cost;
    //scanf("%d%d%d",&ES[i].from, &ES[i].to, &ES[i].cost);
  }
}

int main()
{
  input();
  solve();
  //print();
  output();
}
