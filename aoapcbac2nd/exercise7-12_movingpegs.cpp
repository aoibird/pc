#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> PII;
const int N = 15;
const int MAXS = (1 << N) + 5;
const int pos[N][2] ={
                      {0, 0},
                      {1, 0}, {1, 1},
                      {2, 0}, {2, 1}, {2, 2},
                      {3, 0}, {3, 1}, {3, 2}, {3, 3},
                      {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}
};

int B[5][5];
int DIST[MAXS];
int PRE[MAXS];
PII MOT[MAXS]; // (src, dst)
int S, T;
int dr[6] = {0, 0, -1, 1, -1, 1};
int dc[6] = {-1, 1, 0, 0, -1, 1};

void print_board()
{
  for (int i = 0; i < N; i++) printf("%d", B[pos[i][0]][pos[i][1]]);
  printf("\n");
}

void init()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      B[i][j] = -1;
    }
  }

  for (int i = 0; i < N; i++) {
    B[pos[i][0]][pos[i][1]] = 1;
  }
  memset(DIST, 0, sizeof(DIST));
  memset(PRE, 0, sizeof(PRE));
}

void input()
{
  int e;
  scanf("%d", &e);
  e -= 1;
  B[pos[e][0]][pos[e][1]] = 0;
  T = 1 << e;
  S = (1 << N)- 1 - T;
}

int encode()
{
  int code = 0;
  for (int i = 0; i < N; i++) code += (B[pos[i][0]][pos[i][1]] * (1 << i));
  return code;
}

void decode(int code)
{
  for (int i = 0; i < N; i++) {
    B[pos[i][0]][pos[i][1]] = code&1;
    code = code >> 1;
  }
}

// void test_code()
// {
//   for (int i = 0; i < 20; i++) {
//     decode(i);
//     for (int j = 0; j < N; j++) printf("%d", B[pos[j][0]][pos[j][1]]);
//     int code = encode();
//     printf(" %d\n", code);
//   }
// }

void move(int r, int c, int nr, int nc)
{
  // (nr, nc) src ---> (r, c) dst
  int type;
  if (nr == r && nc > c) type = 0;
  else if (nr == r && nc < c) type = 1;
  else if (nc == c && nr > r) type = 2;
  else if (nc == c && nr < r) type = 3;
  else if (nr > r && nc > c) type = 4;
  else if (nr < r && nc < c) type = 5;
  else type = -1;
  assert(type != -1);

  if (nr + dr[type] == r && nc + dc[type] == c) return;
  for (int i = nr, j = nc; !(i == r && j == c); i += dr[type], j += dc[type]) {
    if (B[i][j] == 0) return;
  }
  // printf("move: (%d,%d)->(%d,%d) %d %d %d\n", nr, nc, r, c, type, dr[type], dc[type]);
  for (int i = nr, j = nc; !(i == r && j == c); i += dr[type], j += dc[type]) {
    B[i][j] = 0;
    // printf("(%d,%d)\n", i, j);
  }
  //  for (int i = nr; i != r; i += dr[type]) {
  //   for (int j = nc; j != c; j += dc[type]) {
  //     printf("(%d,%d)\n", i, j);
  //     B[i][j] = 0;
  //   }
  // }
  B[r][c] = 1;
}

int bfs()
{
  queue<int> q;
  q.push(S);
  DIST[S] = 0;
  PRE[S] = -1;
  MOT[S] = PII(-1, -1);

  while (!q.empty()) {
    // get current state
    int s = q.front(); q.pop();
    decode(s);

    // the goal state
    if (s == T) {
      return DIST[s];
    }

    // get next state
    for (int dst = 0; dst < N; dst++) { // empty hole number
      int r = pos[dst][0];
      int c = pos[dst][1];
      // printf("(%d,%d) %d %d\n", r, c, dst, B[r][c]);
      if (B[r][c] == 1) continue; // is not empty

      // possible source
      for (int src = 0; src < N; src++) {
        int nr = pos[src][0];
        int nc = pos[src][1];
        // printf("(%d,%d) %d --> (%d,%d) %d\n", nr, nc, src, r, c, dst);

        if (B[nr][nc] == 1 && src != dst
            && (nr == r || nc == c || (nr - r == nc - c))) {
          // for (int i = 0; i < N; i++) printf("%d", B[pos[i][0]][pos[i][1]]);
          // printf("\n");
          move(r, c, nr, nc); // move
          // for (int i = 0; i < N; i++) printf("%d", B[pos[i][0]][pos[i][1]]);
          // printf("\n");

          int ns = encode();
          if (DIST[ns] == 0) { // unvisited
            q.push(ns);
            DIST[ns] = DIST[s] + 1;
            PRE[ns] = s;
            MOT[ns] = PII(src, dst);
          }

          decode(s); // put back

        }
      }
    }

  }

  return -1;
}

void print_path()
{
  vector<PII> path;
  int s = T;
  while(s != S) {
    path.push_back(MOT[s]);
    s = PRE[s];
  }

  printf("%d\n", (int)path.size());
  for (int i = path.size()-1; i >= 0; i--) {
    printf("%d %d", path[i].first+1, path[i].second+1);
    if (i == 0) printf("\n");
    else printf(" ");
  }


  // decode(S);
  // print_board();
  // for (int i = path.size()-1; i >= 0; i--) {
  //   int src = path[i].first;
  //   int dst = path[i].second;
  //   int r = pos[dst][0];
  //   int c = pos[dst][1];
  //   int nr = pos[src][0];
  //   int nc = pos[src][1];
  //   printf("%d: (%d,%d) (%d,%d)->(%d,%d)\n", i, src+1, dst+1, nr, nc, r, c);
  //   move(r, c, nr, nc);
  //   print_board();
  // }
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    init();
    input();
    //test_code();

    int res = bfs();
    // print_board();
    // printf("%d\n", encode());

    // decode(S);
    // print_board();
    // decode(T);
    // print_board();

    if (res == -1) printf("IMPOSSIBLE\n");
    else print_path();
  }
}
