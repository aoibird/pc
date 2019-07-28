#include <iostream>
#include <stdio.h>
#define MAXH 105
#define MAXW 105
using namespace std;

char field[MAXH][MAXW];
int H, W;
int dirh[4] = {-1, 1, 0, 0};
int dirw[4] = {0, 0, -1, 1};
int cnt;

void trace()
{
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%c", field[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void input()
{
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%c", &field[i][j]);
    }
    getchar();
  }

  //trace();
}

void dfs(int h, int w, char type)
{
  field[h][w] = ' ';

  for (int i = 0; i < 4; i++) {
    int nh = dirh[i] + h;
    int nw = dirw[i] + w;
    if (nh >= 0 && nh < H && nw >= 0 && nw < W &&
        field[nh][nw] == type) {
      dfs(nh, nw, type);
    }
  }

}

int main()
{
  while (scanf("%d%d", &H, &W) == 2 && H && W) {
    getchar();
    input();
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (field[i][j] != ' ') {
          dfs(i, j, field[i][j]);
          cnt += 1;
        }
      }
    }

    printf("%d\n", cnt);

    cnt = 0;
  }
}
