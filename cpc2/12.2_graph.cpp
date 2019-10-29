// AOJ ALDS1_11_A
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100+10;
int G[MAXN][MAXN];

int main()
{
  memset(G, 0, sizeof(G));
  int N; scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int from; scanf("%d", &from);
    int t; scanf("%d", &t);
    for (int j = 0; j < t; j++) {
      int to; scanf("%d", &to);
      G[from-1][to-1] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", G[i][j]);
      if (j == N-1) printf("\n");
      else printf(" ");
    }
  }
}
