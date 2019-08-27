#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;

struct Point {
  int x;
  int y;
  Point(int a=0, int b=0) {
    x = a;
    y = b;
  }
};

const int MAXK = 50;
const int MAXD = 210; // 210==1+2+...+20
const int M = MAXD*2+3;
const int INF = 1000000;
int N; // [1, 20]
int K; // [1, 50]
Point B[MAXK+5];
int V[M][M]; // visited, store distance (step)
vector<int> path;
vector<string> allpath;

// N E W S
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int news[4] = {'n', 'e', 'w', 's'};

void debug()
{
  for (int i = M/2-10; i < M/2+10; i++) {
    for (int j = M/2-10; j < M/2+10; j++) {
      if (V[i][j] == INF) printf("X ");
      else if (V[i][j] == -1) printf("  ");
      else printf("%d ", V[i][j]);
    }
    printf("\n");
  }
}

void init()
{
  memset(V, -1, sizeof(V));
}

void input()
{
  scanf("%d%d", &N, &K);
  for (int i = 0; i < K; i++) {
    int bx, by;
    scanf("%d%d", &bx, &by);
    int tx, ty;
    tx = -by;
    ty = bx;
    B[i] = Point(tx, ty);
  }

  for (int i = 0; i < K; i++) {
    V[B[i].x+M/2][B[i].y+M/2] = INF;
  }
}

int blocked(int x, int y, int nx, int ny, int d, int s)
{
  for (int i = 1; i <= s; i++) {
    int tx = x + dx[d] * i;
    int ty = y + dy[d] * i;
    if (V[tx+M/2][ty+M/2] == INF) return 1;
  }

  return 0;
}

void dfs(int x, int y, int dir, int step, int& cnt)
{
  if (step == N) {
    if (x == 0 && y == 0) {
      // for (int i = 0; i < path.size(); i++) {
      //   printf("%c", path[i]);
      // }
      // printf("\n");
      // debug();
      char str[path.size()+1];
      for (int i = 0; i < path.size(); i++) {
        str[i] = path[i];
      }
      str[path.size()] = '\0';
      string str2 = str;
      allpath.push_back(str2);

      cnt++;
    }
    return;
  }

  V[x+M/2][y+M/2] = step;

  for (int i = 0; i < 4; i++) {
      int nx = x + dx[i]*(step+1);
      int ny = y + dy[i]*(step+1);

      if (step != 0 && (dir == i || dir == 3-i)) continue;
      if (blocked(x, y, nx, ny, i, step+1)) continue;
      if (!(nx == 0 && ny == 0) && V[nx+M/2][ny+M/2] != -1) continue;

      path.push_back(news[i]);
      dfs(nx, ny, i, step+1, cnt);
      path.pop_back();
  }

  V[x+M/2][y+M/2] = -1;
}


int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    init();
    input();

    int cnt = 0;
    dfs(0, 0, 0, 0, cnt);

    sort(allpath.begin(), allpath.end());
    for (int i = 0; i < cnt; i++) {
      cout << allpath[i] << "\n";
    }
    printf("Found %d golygon(s).\n\n", cnt);
  }

}
