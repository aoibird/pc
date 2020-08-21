#include <iostream>
#define MAXN 50010
using namespace std;

int par[MAXN*3];
int rnk[MAXN*3];

void init(int n)
{
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x)
{
  if (par[x] == x) {
    return x;
  }
  else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rnk[x] < rnk[y]) {
    par[x] = y;
  }
  else {
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y)
{
  return find(x) == find(y);
}

int N, K;


int main()
{
  scanf("%d%d", &N, &K);
  init(N * 3);

  int wrong = 0;
  for (int i = 0; i < K; i++) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    x -= 1; y -= 1;

    if (x < 0 || x >= N || y < 0 || y >= N) {
      wrong += 1;
      continue;
    }

    if (t == 1) {
      if (same(x, y + N) || same(x, y + 2 * N)) {
        wrong += 1;
      }
      else {
        unite(x, y);
        unite(x + N, y + N);
        unite(x + 2 * N, y + 2 * N);
      }
    }
    else {
      if (same(x, y) || same(x, y + 2 * N)) {
        wrong += 1;
      }
      else {
        unite(x, y + N);
        unite(x + N, y + 2 * N);
        unite(x + 2 * N, y);
      }
    }
  }

  cout << wrong << endl;
}
