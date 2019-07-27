#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 105;
const int MAXM = 105;
char F[MAXN][MAXM];
int N, M; // n, m ~ (0, 100]

void input()
{
  // for each lines/rows, columns
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      scanf("%c", &F[r][c]);
      if (F[r][c] == '.') F[r][c] = 0;
    }
    getchar();
  }
}

void solve()
{
  // for each position if * update 8 surrounding positions
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      if (F[r][c] != '*') continue;

      for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
          int nr = r + dr;
          int nc = c + dc;
          if (nr >= 0 && nr < N && nc >= 0 && nc < M &&
              !(dr == 0 && dc == 0) && F[nr][nc] <= 0) {
            F[nr][nc] -= 1;
          }
        }
      }
    }
  }
}

void print()
{
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      if (F[r][c] > 0) printf("%c", F[r][c]);
      else printf("%d", -F[r][c]);
    }
    printf("\n");
  }
}

int main()
{
  // for each test case run input, solve, print
  int T = 1;
  int first = 1;
  while (scanf("%d%d", &N, &M) == 2) {
    if (N == 0 && M == 0) break;
    getchar();
    if (first) first = 0;
    else printf("\n");
    printf("Field #%d:\n", T);
    input();
    solve();
    print();
    T++;
  }
}
