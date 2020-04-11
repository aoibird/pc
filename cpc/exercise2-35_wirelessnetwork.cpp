#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> PII;
const int MAXN = 1000+10;
// const int MAXD = 20000+10;
PII A[MAXN];
vector<int> G[MAXN];
bool W[MAXN];
int N;
int D;

int par[MAXN];
int rnk[MAXN];

void init()
{
  for (int i = 1; i <= N; i++) { par[i] = i; rnk[i] = 0; }
}

int find(int x)
{
  int i = x;
  while (par[i] != i) i = par[i];
  return i;
}

bool same(int x, int y)
{
  return find(x) == find(y);
}

void merge(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rnk[x] < rnk[y]) par[x] = y;
  else if (rnk[x] > rnk[y]) par[y] = x;
  else { par[y] = x; rnk[x]++; }
}

bool can(int i, int j)
{
  int dx = A[i].first - A[j].first;
  int dy = A[i].second - A[j].second;
  return dx*dx + dy*dy <= D*D;
}

int main()
{
  scanf("%d%d", &N, &D);
  for (int i = 1; i <= N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    A[i] = PII(x, y);
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i != j && can(i, j)) G[i].push_back(j);
    }
  }

  // for (int i = 1; i <= N; i++) {
  //   printf("%d: ", i);
  //   for (int j = 0; j < G[i].size(); j++) printf("%d ", G[i][j]);
  //   printf("\n");
  // }

  init();
  char op;
  while (scanf("%s", &op) > 0) {
    if (op == 'O') {
      int p; scanf("%d", &p);
      W[p] = true;
      for (int i = 0; i < G[p].size(); i++)
        if (W[G[p][i]]) merge(p, G[p][i]);
    }
    else if (op == 'S') {
      int x, y; scanf("%d%d", &x, &y);
      if (same(x, y)) printf("SUCCESS\n");
      else printf("FAIL\n");
    }
    else ;

    //for (int i = 1; i <= N; i++) printf("%d ", par[i]); printf("\n");
  }
}
