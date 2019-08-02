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
int visit[MAXB][MAXB][MAXB];

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


void print()
{
  printf("start - target\n");
  for (int i = 0; i < N; i++) {
    printf("%d -> %d\n", S[i], T[i]);
  }

  printf("board\n");
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      printf("%2d ", board[r][c]);
    }
    printf("\n");
  }

  printf("graph\n");
  for (int i = 0; i < V; i++) {
    printf("%d: ", i);
    for (int j = 0; j < G[i].size(); j++) {
      printf("%d ", G[i][j]);
    }
    printf("\n");
  }
}

void init()
{
  // start and target point
  for (int i = 0; i < N; i++) S[i] = T[i] = 0;
  // graph
  V = 0;
  for (int i = 0; i < MAXB; i++) G[i].resize(0);
  // board
  // visit
  memset(visit, 0, sizeof(visit));
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
}

int valid(int cx, int cy, int cz, int nx, int ny, int nz)
{
  if (N == 1) {
    return 1;
  }
  else if (N == 2) {
    if ((nx == ny) || (nx == cy && ny == cx)) return 0;
    else return 1;
  }
  else if (N == 3) {
    if (nx == cx && ny == cy && nz == cz) return 0;
    if ((nx == ny) || (nx == nz) || (ny == nz)) return 0;
    else if ((nx == cy && ny == cx) || (nx == cz && nz == cx) || (ny == cz && nz == cy)) return 0;
    else {
      // int curr[3] = {cx, cy, cz};
      // int next[3] = {nx, ny, nz};
      // sort(curr, curr+3);
      // sort(next, next+3);
      // for (int i = 0; i < 3; i++) if (curr[i] != next[i]) return 1;
      // return 0;
      return 1;
    }
  }
  else return 0;
}

void solve()
{
  // N = 1, 2, 3  ~ state[i][0][0]: (x, 0, 0), state[i][j][0]: (x, y, 0), state[i][j][k]: (x, y, z)
  queue<State> q;
  queue<int> s;
  //queue<State> p;
  q.push(State(S[0], S[1], S[2])); // start
  s.push(0);
  //p.push(State(-1, -1, -1));
  //printf("(%d,%d,%d)~%d\n", S[0], S[1], S[2], 0);

  int cnt = 1;
  while (!q.empty()) {

    State curr = q.front(); q.pop();
    int step = s.front(); s.pop();
    //State pre = p.front(); p.pop();
    //printf("(%d,%d,%d)~%d(%d,%d,%d)%d\n", curr.x, curr.y, curr.z, step, pre.x, pre.y, pre.z, cnt);

    if (curr.x == T[0] && curr.y == T[1] && curr.z == T[2]) {
      printf("%d\n", step);
      break;
    }

    // next state
    for (int x = 0; x < G[curr.x].size(); x++) {
      for (int y = 0; y < G[curr.y].size(); y++) {
        for (int z = 0; z < G[curr.z].size(); z++) {
          int nx = G[curr.x][x];
          int ny = (N < 2) ? 0 : G[curr.y][y];
          int nz = (N < 3) ? 0 : G[curr.z][z];

          if (visit[nx][ny][nz]) continue;

          if (valid(curr.x, curr.y, curr.z, nx, ny, nz)) {
            //printf("%d %d %d\n", nx, ny, nz);
            q.push(State(nx, ny, nz));
            s.push(step+1);
            //p.push(State(curr.x, curr.y, curr.z));
            visit[nx][ny][nz] = 1;
          }

          if (N < 3) break; // N == 1, 2 only once
        }
        if (N < 2) break; // N == 1 only once
      }
    }

    cnt++;
  }

  //printf("%d\n", cnt);
}

int main()
{
  while (scanf("%d%d%d", &C, &R, &N) == 3) {
    getchar();
    if (R == 0 && C == 0 && N == 0) break;

    init();
    input(); // read graph
    //print();
    solve();
  }

}
