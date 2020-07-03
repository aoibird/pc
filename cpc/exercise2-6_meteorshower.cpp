// POJ 3669
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
  int r, c, d;
  Node(int ri=0, int ci=0, int di=0) { r = ri; c = ci; d = di; }
};

const int INF = 100000;
const int MAXR = 300+10;
const int MAXC = 300+10;
int GRID[MAXR][MAXC];
int D[MAXR][MAXC];
int M;
int T;
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};

void print()
{
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (GRID[i][j] == INF) printf("# ");
      else printf("%d ", GRID[i][j]);
    }
    printf("\n");
  }
}

void print_d()
{
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", D[i][j]);
    }
    printf("\n");
  }
}

void input()
{
  T = 0;
  for (int i = 0; i < M; i++) {
    int r, c, t;
    scanf("%d%d%d", &r, &c, &t);
    T = max(T, t);
    if (t < GRID[r][c]) GRID[r][c] = t;
    // printf("r c t %d %d %d\n", r, c, t);
    for (int j = 0; j < 4; j++) {
      int nr = r+dr[j];
      int nc = c+dc[j];
      if (nr >= 0 && nr < MAXR && nc >= 0 && nc < MAXC
        && (t < GRID[nr][nc])) {
        // printf("    nr nc nt %d %d %d\n", nr, nc, t);
        GRID[nr][nc] = t;
      }
    }
  }
}


int solve()
{
  queue<Node> q;
  q.push(Node(0, 0, 0));
  D[0][0] = 0;
  while (!q.empty()) {
    Node curr = q.front(); q.pop();
    int r = curr.r;
    int c = curr.c;
    int d = curr.d;
    if (GRID[r][c] >= INF) { return d; }
    for (int i = 0; i < 4; i++) {
      int nr = r+dr[i];
      int nc = c+dc[i];
      int nd = d + 1;
      if (nr >= 0 && nr < MAXR && nc >= 0 && nc < MAXC
        && nd < GRID[nr][nc] && D[nr][nc] == 0) {
        q.push(Node(nr, nc, nd));
        D[nr][nc] = nd;
      }
    }
  }
  return -1;
}

int main()
{
  while (scanf("%d", &M) == 1) {
    for (int i = 0; i < MAXR; i++) for (int j = 0; j < MAXC; j++) GRID[i][j] = INF;
    memset(D, 0, sizeof(D));
    input();
    // print();
    int res = solve();
    printf("%d\n", res);
    // print_d();
  }
}
