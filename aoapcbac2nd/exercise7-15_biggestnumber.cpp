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

const int MAXSIZE = 15;
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};


int R, C; // R,C ~ [2, 15]; R*C ~ [4, 30]
int B[MAXSIZE+5][MAXSIZE+5];
int V[MAXSIZE+5][MAXSIZE+5];
vector<PII> path;
int best = 0;

void input()
{
  char ch;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%c", &ch);
      if (ch == '#') B[i][j] = 0;
      else B[i][j] = ch-'0';
    }
    getchar();
  }
}

int dfs(int r, int c)
{
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr >= 0 && nr < R && nc >= 0 && nc < C
        && B[nr][nc] != 0 && V[nr][nc] == 0) {
      path.push_back(PII(nr, nc));
      V[r][c] = 1;
      res = dfs(nr, nc);
      V[r][c] = 0;
      path.pop_back();
    }
  }

  if (res == 1) return 1;
  else {
    int sum = 0;
    for (int i = 0; i < path.size(); i++) {
      int number = B[path[i].first][path[i].second];
      sum *= 10;
      sum += number;
    }
    best = max(best, sum);

    return 1;
  }
}

void print_board()
{
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  while (scanf("%d%d", &R, &C) == 2) {
    getchar();
    if (R == 0 && C == 0) break;
    input();

    //print_board();

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (B[i][j] != 0) {
          memset(V, 0, sizeof(V));
          path.push_back(PII(i, j));
          dfs(i, j);
          path.pop_back();
        }
      }
    }

    printf("%d\n", best);
  }
}
