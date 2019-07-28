#include <iostream>
#include <queue>
#define M 1000
#define N 1000
#define INF 10000000
using namespace std;

char maze[M][N];
int steps[M][N];
int m, n;
int sx, sy, gx, gy;
int row[4] = {0, 1, 0, -1};
int col[4] = {1, 0, -1, 0};

void bfs(int x, int y)
{
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));
  steps[x][y] = 0;

  while (!q.empty()) {
    pair<int, int> loc = q.front(); q.pop();
    int i = loc.first;
    int j = loc.second;
    int s = steps[i][j];
    if (i == gx && j == gy) break;

    for (int k = 0; k < 4; k++) {
      int posx = i + row[k];
      int posy = j + col[k];
      if (posx >= 0 && posx < m && posy >= 0 && posy < n &&
          maze[posx][posy] != '#' && steps[posx][posy] == INF) {
        q.push(make_pair(posx, posy));
        steps[posx][posy] = s + 1;
      }
    }
  }

}


int main()
{
  cin >> m >> n;
  cin >> sx >> sy;
  cin >> gx >> gy;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      maze[i][j] = c;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      steps[i][j] = INF;
    }
  }

  bfs(sx, sy);

  cout << steps[gx][gy] << endl;
}
