#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <queue>
#define INF -1
#define MAXH 1050
#define MAXW 1050
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

char field[MAXH][MAXW];
ll dist[MAXH][MAXW];
int H, W, N;
int sh, sw;
int ch, cw;

int dirh[4] = {-1, 1, 0, 0};
int dirw[4] = {0, 0, -1, 1};

void trace()
{
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%c", field[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void input()
{
  scanf("%d%d%d", &H, &W, &N); getchar();
  //printf("%d %d %d\n", H, W, N);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%c", &field[i][j]);
      if (field[i][j] == 'S') {
        sh = i;
        sw = j;
      }
      //else if (isdigit(field[i][j])) {
      //  printf("digit: %c %d %d\n", field[i][j], i, j);
      //}
    }
    getchar();
  }
  //printf("sh sw: %d %d\n", sh, sw);

  //trace();
}

ll bfs(int h, int w, int n)
{
  queue<P> q;
  q.push(P(h, w));
  while (!q.empty()) {
    P pos = q.front(); q.pop();
    //printf("h, w: %d %d\n", h, w);
    int nh, nw;
    for (int i = 0; i < 4; i++) {
      nh = dirh[i] + pos.first;
      nw = dirw[i] + pos.second;

      //printf("nh, nw: %d %d %c %d\n",
      //       nh, nw, field[nh][nw], dist[nh][nw]);
      if (nh >= 0 && nh < H && nw >= 0 && nw < W &&
          field[nh][nw] != 'X' &&
          dist[nh][nw] == INF) {
        q.push(P(nh, nw));
        dist[nh][nw] = dist[pos.first][pos.second] + 1;
        //if (isdigit(field[nh][nw])) printf("%c\n", field[nh][nw]);
        if (field[nh][nw] == (n+'0')) {
          ch = nh;
          cw = nw;
          //printf("%d %d %c %lld\n", ch, cw, field[nh][nw], dist[nh][nw]);
          return dist[nh][nw];
        }
      }
    }
  }

  return 0;
}

int main()
{
  input();
  ll cnt = 0;
  ch = sh;
  cw = sw;
  for (int i = 1; i <= N; i++) {
    //printf("loop: %d %d %d\n", ch, cw, i);
    memset(dist, INF, sizeof(dist));
    dist[ch][cw] = 0;
    cnt = cnt + bfs(ch, cw, i);
  }

  printf("%lld\n", cnt);
}
