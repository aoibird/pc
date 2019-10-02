// POJ 2139
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 100000000;
const int MAXN = 300+10;
int G[MAXN][MAXN];
int N; // [2, 300]
int M; // [1, 10000]
int MOV[MAXN];

void print_g()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (G[i][j] == INF) printf(" X ");
      else printf("%2d ", G[i][j]);
    }
    printf("\n");
  }
}

void connect(int k)
{
  for (int i = 0; i < k-1; i++) {
    int x = MOV[i];
    for (int j = i+1; j < k; j++) {
      int y = MOV[j];
      G[x][y] = G[y][x] = 1;
    }
  }
}

void input()
{
  scanf("%d%d", &N, &M); // line 1

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) G[i][j] = 0;
      else G[i][j] = INF;
    }
  }

  for (int i = 0; i < M; i++) { // movies
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", MOV+j);
      MOV[j] -= 1;
    }
    connect(k);
  }
}

int main()
{
  input();
  // print_g();
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (G[i][j] > G[i][k] + G[k][j]) G[i][j] = G[i][k] + G[k][j];
      }
    }
  }
  //print_g();
  int best = INF;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
      sum += G[i][j];
    }
    best = min(sum, best);
  }
  printf("%d\n", (best*100)/(N-1));
}
