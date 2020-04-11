#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100000+10;
vector<int> D[MAXN];
int N, M;

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

void solve()
{
  for (int i = 0; i < M; i++) {
    char op; int a, b;
    scanf("%c %d%d", &op, &a, &b); getchar();
    // printf("%d %c %d %d\n", i, op, a, b);
    if (op == 'A') {
      if (D[a].size() == 0 || D[b].size() == 0) printf("Not sure yet.\n");
      else if (find(a) == find(b)) printf("In the same gang.\n");
      else if (find(D[a][0]) == find(b)) printf("In different gangs.\n");
      else printf("Not sure yet.\n");
    }
    else if (op == 'D') { // different
      D[a].push_back(b);
      D[b].push_back(a);
      merge(b, D[a][0]);
      merge(a, D[b][0]);
      // printf("\n");
    }
    else ;
  }
}

int main()
{
  int TC;
  scanf("%d", &TC);
  for (int i = 0; i < TC; i++) {
    // printf("TC %d\n", i);
    scanf("%d%d", &N, &M); getchar();
    init();
    for (int i = 0; i < N; i++) D[i].clear();
    solve();
  }
}
