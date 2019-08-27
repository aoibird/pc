#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#define E 0
#define W 1
#define R 2
#define B 3
using namespace std;

const int N = 3;
const int INF = 900000;
const int POSS = 262144+6;
int ER, EC;
int board[N][N];
int target[N][N];
int S;
int T; // target state
int visited[POSS]; // 4*4*4*4*4 .. *4 == 262144
int pre[POSS];

// W 0 R 1 B 2
// T ^ 0, B v 1, L < 2, R > 3
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int nextcolor[4][2] = { // 0,1 2,3
                       {9, 9}, // E
                       {R, B}, // W
                       {W, B}, // R
                       {R, W}  // B
};

struct Node {
  int code;
  int step;
  Node (int c=0, int s=0) {
    code = c;
    step = s;
  }
};

void print(int st[N][N])
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", st[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int move(int x)
{
  int nr = ER + dr[x];
  int nc = EC + dc[x];

  if (nr < 0 || nr >= N || nc < 0 || nc >= N) return 0;

  int ncolor = board[nr][nc];

  int vh; // vertical 0 horizonal 1
  if (x == 0 || x == 1) vh = 0;
  else vh = 1;

  // printf("ER EC (%d %d) nr nc (%d %d)\n", ER, EC, nr, nc);
  // printf("ncolor %d vh %d\n", ncolor, vh);
  board[ER][EC] = nextcolor[ncolor][vh];
  board[nr][nc] = E;
  ER = nr;
  EC = nc;

  return 1;
}

int encode(int st[N][N])
{
  // int code = 0;
  // for (int i = 0; i < N*N; i++) {
  //   int cnt = 0;
  //   for (int j = i+1; j < N*N; j++)
  //     if (st[i/N][i%N] > st[j/N][j%N]) cnt++;
  //   code += st[i/N][j%N] * cnt;
  // }

  int code = 0;
  for (int i = 0, w = 1; i < N*N; i++, w *= 4) {
    int r = i/N;
    int c = i%N;
    int color = st[r][c];

    code += (color * w);
  }

  return code;
}

void decode(int code)
{
  for (int i = 0; i < N*N; i++, code /= 4) {
    board[i/N][i%N] = code % 4;
    if (board[i/N][i%N] == E) { ER = i/N; EC = i%N; }
  }

}

int bfs()
{
  queue<Node> q;
  q.push(Node(S, 0));
  visited[S] = 0;
  pre[S] = -1;

  while (!q.empty()) {
    Node n = q.front(); q.pop();
    int code = n.code;
    int step = n.step;
    if (code == T) return step;

    decode(code);
    // printf("code = %d\n", code);
    // print(board);
    // printf("(%d %d) next:\n", ER, EC);
    for (int k = 0; k < 4; k++) {
      if (move(k) == 0) continue; // move

      int ncode = encode(board);
      if (step + 1 < visited[ncode]) {
        // printf("%d\n", ncode);
        // if (step + 1 == 13 && ncode == T) {
        //   printf("ncode = %d\n", ncode);
        //   print(board);
        // }
        q.push(Node(ncode, step+1));
        visited[ncode] = step+1;
        pre[ncode] = code;
      }
      decode(code); // put back
    }

    // printf("\n");
  }

  return -1;
}

void print_path()
{
  int p = T;
  while (p != -1) {
    printf("%d(%d)\n", p, visited[p]);
    decode(p);
    print(board);

    p = pre[p];
  }
  printf("\n");
}

void input()
{
  // printf("%d %d\n", ER, EC);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == ER && j == EC) board[i][j] = E;
      else board[i][j] = W;

      int ch = getchar();
      target[i][j] = (ch == 'W') ? W : (ch == 'R') ? R :
                     (ch == 'B') ? B : (ch == 'E') ? E : -1;
      getchar();
    }
  }
  // printf("\n");

  S = encode(board);
  T = encode(target);
  // printf("start: %d target: %d\n", S, T);
  //memset(visited, 0, sizeof(visited));
  for (int i = 0; i < POSS; i++) visited[i] = INF;
}

int main()
{
  while (scanf("%d%d", &EC, &ER) == 2) {
    if (ER == 0 && EC == 0) break;
    ER -= 1; EC -= 1;
    getchar();
    input();

    int steps = bfs();

    print_path();
    printf("%d\n", steps);
  }
}
