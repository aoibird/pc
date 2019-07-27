#include <iostream>
#define MAXM 105
#define MAXN 105
using namespace std;

char field[MAXM][MAXN];
int M, N, cnt;

void input()
{
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      field[i][j] = getchar();
    }
    getchar();
  }
}

void dfs(int r, int c)
{
  field[r][c] = '*';
  for (int dr = -1; dr <= 1; dr++) {
    for (int dc = -1; dc <= 1; dc++) {
      int nr = dr + r;
      int nc = dc + c;
      if (nr >= 0 && nr < M && nc >= 0 && nc < N &&
          field[nr][nc] == '@') {
        dfs(nr, nc);
      }
    }
  }
}


int main()
{
  while (scanf("%d%d", &M, &N) == 2 && M && N) {
    getchar();
    input();
    cnt = 0;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (i >= 0 && i < M && j >= 0 && j < N &&
            field[i][j] == '@') {
          dfs(i, j);
          cnt++;
        }
      }
    }
    printf("%d\n", cnt);
  }
}
