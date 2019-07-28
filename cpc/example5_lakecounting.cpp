#include <iostream>
#define M 1000
#define N 1000
using namespace std;

char field[M][N];
int m, n;


void dfs(int x, int y)
{
  field[x][y] = '.';
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {

      int nx = x + i;
      int ny = y + j;

      if (nx >= 0 && nx < m && ny >= 0 && ny < n
          && field[nx][ny] == 'W') {
        dfs(nx, ny);
      }
    }
  }
}


int main()
{
  // input
  int cnt = 0;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      field[i][j] = c;
    }
  }

  // deepth first search
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (field[i][j] == 'W') {
        dfs(i, j);
        cnt++;
      }
    }
  }

  // output
  cout << cnt << endl;
}
