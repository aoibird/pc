#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define N 8
#define INF 100000
using namespace std;
typedef pair<int, int> P;

int dist[N][N];
int visit[N][N];
char S[5], T[5];
int SR, SC, TR, TC;
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void printdist()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", dist[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void init()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = INF;
      visit[i][j] = 0;
    }
  }
}

void solve()
{
  queue<P> q;
  queue<int> qd;
  q.push(P(SR, SC));
  qd.push(0);
  visit[SR][SC] = 1;
  dist[SR][SC] = 0;

  while (!q.empty()) {
    P pos = q.front(); q.pop();
    int r = pos.first;
    int c = pos.second;
    int d = qd.front(); qd.pop();

    for (int i = 0; i < 8; i++) {
      int nr = dr[i] + r;
      int nc = dc[i] + c;
      if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visit[nr][nc]) {
        dist[nr][nc] = d + 1;
        visit[nr][nc] = 1;
        q.push(P(nr, nc));
        qd.push(d+1);
        // if (d == 0) {
        //   printf("nr nc r c %d %d %d %d\n", nr, nc, r, c);
        // }
      }

    }
  }

}


int main()
{
  while (scanf("%s %s", S, T) == 2) {
    SC = S[0] - 'a';
    SR = 8 + '0' - S[1];
    TC = T[0] - 'a';
    TR = 8 + '0' - T[1];
    // printf("%s %s\n", S, T);
    // printf("%d %d %d %d\n", SR, SC, TR, TC);
    init();
    //printdist();
    solve();
    //printdist();
    // printf("%d %d %d %d\n", SR, SC, TR, TC);
    printf("To get from %s to %s takes %d knight moves.\n", S, T, dist[TR][TC]);
  }
}
