#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
#define N 0
#define E 1
#define W 2
#define S 3
#define FO 0
#define LE 1
#define RI 2
using namespace std;

struct State {
  int r;
  int c;
  int d;
  State(int row=0, int col=0, int dir=0) {
    r = row;
    c = col;
    d = dir;
  }
};

const int MAXLENNAME = 20;
const int R = 9;
const int C = 9;
const int D = 4;
const int T = 3;
int turn[D][T] = {// F L R
                  {N, W, E}, // N
                  {E, N, S}, // E
                  {W, S, N}, // W
                  {S, E, W}  // S
};
int dr[D] = {-1, 0, 0, 1}; // N E W S
int dc[D] = {0, 1, -1, 0};
int FLR[3] = {'F', 'L', 'R'};
int NEWS[4] = {'N', 'E', 'W', 'S'};

int MAZE[R+3][C+3][D][T];
int DIST[R+3][C+3][D];
State PRE[R+3][C+3][D];
int SR, SC, SD, TR, TC;


void print_maze()
{
  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      printf("%d %d ", r, c);
      for (int d = 0; d < D; d++) {
        printf("%c:", NEWS[d]);
        for (int t = 0; t < T; t++) {
          if (MAZE[r][c][d][t] == 1) printf("%c", FLR[t]);
        }
        printf(" ");
      }
      printf("\n");
    }
  }
}

void nstate(int r, int c, int d, int t,
            int& nr, int& nc, int& nd)
{
  nd = turn[d][t];
  nr = r + dr[nd];
  nc = c + dc[nd];
}
/*
void test_nstate()
{
  int r = 3;
  int c = 4;
  for (int d = 0; d < D; d++) {
    for (int t = 0; t < T; t++) {
      int nr, nc, nd;
      nstate(r, c, d, t, nr, nc, nd);
      printf("(%d, %d, %c) %c-> (%d, %d, %c)\n",
             r, c, NEWS[d], FLR[t], nr, nc, NEWS[nd]);
    }
  }
}
*/

void init()
{
  memset(DIST, 0, sizeof(DIST));
  memset(MAZE, 0, sizeof(MAZE));
}

int rev_news(char ch)
{
  return (ch == 'N') ? N : (ch == 'E') ? E :
    (ch == 'W') ? W : (ch == 'S') ? S : -1;
}

int rev_flr(char ch)
{
  return (ch == 'F') ? FO : (ch == 'L') ? LE :
    (ch == 'R') ? RI : -1;
}

void input()
{
  char ch;
  scanf("%d %d %c %d %d", &SR, &SC, &ch, &TR, &TC);
  SD = rev_news(ch);
  MAZE[SR][SC][SD][SD] = 1;

  while (1) {
    int r, c, d, t;
    // r, c
    scanf("%d", &r);
    if (r == 0) break;
    scanf("%d", &c); getchar();

    // d, t
    while ((ch = getchar()) != '*') {
      d = rev_news(ch);
      assert(d != -1);

      while ((ch = getchar()) != ' ') {
        t = rev_flr(ch);
        assert(t != -1);

        MAZE[r][c][d][t] = 1;
      }
    }
  }

  //print_maze();
}

int bfs()
{
  queue<State> q;
  // leave start state unvisited
  int r, c, d;
  nstate(SR, SC, SD, 0, r, c, d);
  q.push(State(r, c, d));
  DIST[r][c][d] = 1;
  PRE[r][c][d] = State(SR, SC, SD);

  while (!q.empty()) {
    // get current state
    State s = q.front(); q.pop();
    /*
    printf("(%d, %d, %c) %d\n", s.r, s.c,
           NEWS[s.d], DIST[s.r][s.c][s.d]);
    */

    // the goal state, break
    if (s.r == TR && s.c == TC) {
      return DIST[s.r][s.c][s.d];
    }

    // push next state (if valid)
    for (int t = 0; t < T; t++) {
      int nr, nc, nd;
      nstate(s.r, s.c, s.d, t, nr, nc, nd);
      /*
        printf("  %d -> (%d, %d, %c) %d\n",
             MAZE[s.r][s.c][s.d][t], nr, nc, NEWS[nd],
             DIST[nr][nc][nd]);
      */

      if (MAZE[s.r][s.c][s.d][t] == 1
          && DIST[nr][nc][nd] == 0) {
        q.push(State(nr, nc, nd));
        DIST[nr][nc][nd] = DIST[s.r][s.c][s.d]+1;
        PRE[nr][nc][nd] = State(s.r, s.c, s.d);
      }
    }
  }

  return -1;
}

void print_path()
{
  vector<State> path;
  State s;

  for (int i = 0; i < D; i++) {
    if (DIST[TR][TC][i] != 0) s = State(TR, TC, i);
  }
  //printf("(%d %d %c)\n", s.r, s.c, NEWS[s.d]);

  while (1) {
    path.push_back(State(s.r, s.c, s.d));
    if (s.r == SR && s.c == SC) break;

    s = PRE[s.r][s.c][s.d];
  }

  int cnt = 0;
  for (int i = path.size()-1; i >= 0; i--) {
    if (cnt % 10 == 0) printf(" ");
    printf(" (%d,%d)", path[i].r, path[i].c); //cnt++;
    if (++cnt % 10 == 0) printf("\n");
  }
  if (path.size() % 10 != 0) printf("\n");
}

int main()
{
  while (1) {
    char name[MAXLENNAME];
    scanf("%s", name);
    if (name[0] == 'E' && name[1] == 'N'
        && name[2] == 'D') break;
    printf("%s\n", name);
    init();
    input();

    int res = bfs();

    if (res == -1) printf("  No Solution Possible\n");
    else print_path();
  }
}
