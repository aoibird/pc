#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 8;

char buff[100];
int G[MAXN][MAXN];
int m;
int visit[MAXN];
int P[MAXN];
int F[MAXN];
char C[MAXN];
int CN;

int find(char c)
{
  for (int i = 0; i < CN; i++) if (C[i] == c) return i;

  return -1;
}

void print()
{
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) printf("%d ", G[i][j]);
    printf("\n");
  }
  printf("\n");
}

void input()
{
  memset(G, 0, sizeof(G));
  memset(P, 0, sizeof(P));
  memset(visit, 0, sizeof(visit));
  CN = 0;

  // read line
  int c, t = 0;
  while ((c = getchar()) != '\n') buff[t++] = c;
  buff[t] = '\0';

  // get symbol
  t = 0;
  while (buff[t] != '\0') {
    int c = buff[t];
    if (isalpha(c) && find(c) == -1) C[CN++] = c;
    t++;
  }
  sort(C, C+CN);

  char *p = buff;
  while (1) {
    int c = *p++;
    int from = find(c); p++;

    while ((c = *p++) != ';' && c != '\0') {
      int to = find(c);
      G[from][to] = 1;
      G[to][from] = 1;
    }
    if (c == '\0') break;
  }

}

int getbandwidth(int curr)
{
  int M = 0;
  for (int i = 0; i <= curr; i++) {
    int v1 = P[i];
    for (int j = i+1; j <= curr; j++) {
      int v2 = P[j];
      if (G[v1][v2]) {
        M = max(M, j-i);
      }
    }
  }

  return M;
}


void permulation(int curr)
{
  if (curr == CN) {
    int w = getbandwidth(curr-1);
    if (w < m) {
      for (int i = 0; i < CN; i++) F[i] = P[i];
      m = w;
    }
  }
  else {
    for (int i = 0; i < CN; i++) {
      if (!visit[i]) {
        visit[i] = 1;
        P[curr] = i;
        if (getbandwidth(curr) <= m) permulation(curr+1);
        visit[i] = 0;
      }
    }
  }
}

int main()
{
  int c;
  while ((c = getchar()) != '#') {
    ungetc(c, stdin);
    input();
    //print();

    m = 100;
    permulation(0);

    for (int i = 0; i < CN; i++) printf("%c ", C[F[i]]);
    printf("-> %d\n", m);
  }
}
