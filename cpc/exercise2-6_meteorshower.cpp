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

struct Meteor {
  int time;
  int row;
  int col;
  Meteor(int t=0, int r=0, int c=0) {
    time = t;
    row = r;
    col = c;
  }
  bool operator<(const Meteor& m) const {
    return time < m.time;
  }
};

struct Node {
  int r;
  int c;
  int d;
  Node(int ri=0, int ci=0, int di=0) {
    r = ri;
    c = ci;
    d = di;
  }
  bool operator<(const Node& n) const {
    return d < n.d;
  }
};

const int INF = 100000;
const int MAXR = 300;
const int MAXC = 300;
//const int MAXM = 50000;
int GRID[MAXR+10][MAXC+10];
//Meteor METEORS[MAXM];
int M;
int T;
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};

void input()
{
  T = 0;
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    int r, c, t;
    scanf("%d%d%d", &r, &c, &t);
    T = max(T, t);
    //METEORS[i] = Meteor(t, x, y);
    GRID[r][c] = t;
    for (int i = 0; i < 4; i++) {
      int nr = r+dr[i];
      int nc = c+dc[i];
      if (nr >= 0 && nr < MAXR && nc >= 0 && nc < MAXC
          && (t < GRID[nr][nc])) {
        GRID[nr][nc] = t;
      }
    }
  }
}

void print()
{
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (GRID[i][j] == INF) printf("# ");
      else printf("%d ", GRID[i][j]);
    }
    printf("\n");
  }
}

int solve()
{
  queue<Node> q;
  q.push(Node(0, 0, 0));
  for (int t = 0; t < T; t++) {

    while (q.front().d == t) {
      Node curr = q.front(); q.pop();
      int r = curr.r;
      int c = curr.c;
      for (int i = 0; i < 4; i++) {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if (nr >= 0 && nr < MAXR && nc >= 0 && nc < MAXC
            && t+1 < GRID[nr][nc]) {
          q.push(Node(nr, nc, t+1));
        }
      }
    }
  }

  if (q.empty()) return -1;
  else return q.front().d;
}

int main()
{
  for (int i = 0; i < MAXR+10; i++) {
    for (int j = 0; j < MAXC+10; j++)
      GRID[i][j] = INF;
  }
  input();
  int res = solve();
  printf("%d\n", res);
  //print();
}
