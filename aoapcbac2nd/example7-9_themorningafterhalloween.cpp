// UVa 1601
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int MAXR = 16+2;
const int MAXC = 16+2;
const int MAXN = 3+2;
const int MAXB = 192+3; // blank ((16*16)/4)*3 == 192


int S[MAXN]; // start
int T[MAXN]; // target
vector<int> G[MAXB];
int V;
int R; // H ~ [4, 16]
int C; // W ~ [4, 16]
int N; // N ~ [1, 3]

int board[MAXR][MAXC];
int DIST[MAXB][MAXB][MAXB];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct State {
  int x;
  int y;
  int z;
  State(int a=0, int b=0, int c=0) {
    x = a;
    y = b;
    z = c;
  }
};

void init()
{
  // start and target point
  for (int i = 0; i < N; i++) S[i] = T[i] = 0;
  // graph
  V = 0;
  for (int i = 0; i < MAXB; i++) G[i].resize(0);
  // board
  // DIST
  memset(DIST, -1, sizeof(DIST));
}

void input()
{
  // get board, start and target point
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      int ch = getchar();
      // cell
      if (ch == '#') board[r][c] = -1;
      else if (ch == ' ' || isalpha(ch)) board[r][c] = V++;
      else ;
      // start and target point
      if (isupper(ch)) T[ch-'A'] = board[r][c];
      else if (islower(ch)) S[ch-'a'] = board[r][c];
      else ;
    }
    getchar();
  }

  // create minimum graph
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      int from = board[r][c];
      if (from >= 0) {
        G[from].push_back(from); // stand
        for (int i = 0; i < 4; i++) {
          int nr = r + dr[i];
          int nc = c + dc[i];
          if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

          int to = board[nr][nc];
          if (to >= 0) G[from].push_back(to);
        }
      }
      else ;
    }
  }


  if (N == 1) {
    G[V].push_back(V); S[1] = T[1] = V;
    G[V+1].push_back(V+1); S[2] = T[2] = V+1;
  }
  else if (N == 2) {
    G[V].push_back(V); S[2] = T[2] = V;
  }
  else ;
  //printf("(%d,%d,%d) -> (%d,%d,%d)\n", S[0], S[1]);
}

int conflict(int cx, int cy, int nx, int ny)
{
  return (nx == ny || (cx == ny && cy == nx));
}

int solve()
{
  // N = 1, 2, 3  ~ state[i][0][0]: (x, 0, 0), state[i][j][0]: (x, y, 0), state[i][j][k]: (x, y, z)
  queue<State> q;
  q.push(State(S[0], S[1], S[2])); // start
  DIST[S[0]][S[1]][S[2]] = 0;

  while (!q.empty()) {
    State curr = q.front(); q.pop();
    int cx = curr.x;
    int cy = curr.y;
    int cz = curr.z;
    int step = DIST[cx][cy][cz];
    if (cx == T[0] && cy == T[1] && cz == T[2]) return step;

    // next state
    for (int x = 0; x < G[cx].size(); x++) {
      int nx = G[cx][x];
      for (int y = 0; y < G[cy].size(); y++) {
        int ny = G[cy][y];
        if (conflict(cx, cy, nx, ny)) continue;
        for (int z = 0; z < G[cz].size(); z++) {
          int nz = G[cz][z];

          if (DIST[nx][ny][nz] != -1) continue;
          if (conflict(cx, cz, nx, nz)) continue;
          if (conflict(cy, cz, ny, nz)) continue;

          q.push(State(nx, ny, nz));
          DIST[nx][ny][nz] = step+1;

        }
      }
    }
  }

  return -1;
}

int main()
{
  while (scanf("%d%d%d", &C, &R, &N) == 3) {
    getchar();
    if (R == 0 && C == 0 && N == 0) break;

    init();
    input(); // read graph
    int res = solve();
    printf("%d\n", res);
  }

}
