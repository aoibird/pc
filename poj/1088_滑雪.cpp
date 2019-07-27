#include <iostream>
#include <string.h>
#define MAXR 1000
#define MAXC 1000

int field[MAXR][MAXC];
int R, C;
int dist[MAXR][MAXC];
int global;

int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, -1, 1};

void trace()
{
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%d ", field[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void input()
{
  memset(dist, 0, sizeof(dist));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%d", &field[i][j]);
    }
  }
  global = 0;

  //trace();
}

int solve(int x, int y)
{
  //printf("x, y: %d %d ", x, y);
  if (x == -1 || y == -1 || x == R || y == C) return 0;
  else if (dist[x][y] > 0) return dist[x][y];


  int m = 0;
  for (int i = 0; i < 4; i++) {
    int nx = dirx[i] + x;
    int ny = diry[i] + y;
    int len;
    if (nx >= 0 && nx < R && ny >= 0 && ny < C &&
      field[nx][ny] < field[x][y]) {
      len = solve(nx, ny);
      if (len > m) {
        m = len;
      }
    }
  }

  global = (m + 1 > global) ? m+1 : global;
  dist[x][y] = m + 1;
  return m + 1;
}

void output()
{
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%d ", dist[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  while (scanf("%d%d", &R, &C) == 2 && R && C) {
    input();
    //output();
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        solve(i, j);
      }
    }
    //output();
    printf("%d\n", global);
  }
}
