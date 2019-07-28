#include <iostream>
#include <algorithm>
#include <string.h>
#define MAXW 40
#define MAXH 40

char maze[MAXH][MAXW];
int visited[MAXH][MAXW];
int cnt;
int h, w;
int x, y;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, -1, 1};

void trace()
{
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void input()
{
  memset(maze, 0, sizeof(maze));
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      maze[i][j] = getchar();
    }
    getchar();
  }

  //trace();
}

void dfs(int sx, int sy)
{
  visited[sx][sy] = 1;
  cnt += 1;
  //printf("%d %d %d\n", sx, sy, cnt);

  for (int i = 0; i < 4; i++) {
    int tx = sx + dirx[i];
    int ty = sy + diry[i];
    //printf("   %d %d %c %d\n", tx, ty, maze[tx][ty], visited[tx][ty]);
    if (tx >= 0 && tx < h && ty >= 0 && ty < w &&
        maze[tx][ty] == '.' && visited[tx][ty] == 0) {
      dfs(tx, ty);
    }
  }

}

void solve()
{
  cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (maze[i][j] == '@') {
        x = i;
        y = j;
        break;
      }
    }
  }

  dfs(x, y);
}


int main()
{
  while (scanf("%d%d", &w, &h) == 2 && h && w) {
    getchar();
    input();
    solve();
    printf("%d\n", cnt);
  }
}
