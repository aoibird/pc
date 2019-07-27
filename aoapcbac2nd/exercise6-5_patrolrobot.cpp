#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXM 30
#define MAXN 30
#define INF 4000
using namespace std;
typedef pair<int, int> P;

int field[MAXM][MAXN];
int dist[MAXM][MAXN];
int visit[MAXM][MAXN];
int M, N, K;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};


void print()
{
  printf("M N K %d %d %d\n", M, N, K);
  //printf("field ======\n");
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      printf("%d(%d) ", field[i][j], dist[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void input()
{
  scanf("%d%d", &M, &N);
  scanf("%d", &K);
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &field[i][j]);
      dist[i][j] = INF;
      visit[i][j] = 0;
    }
  }

  //print();
}

void solve()
{
  queue<int> qk;
  queue<P> q;
  queue<int> qd;
  q.push(P(1, 1));
  qk.push(0);
  qd.push(0);
  visit[1][1] = 1;
  dist[1][1] = 0;

  while (!q.empty()) {
    P pos = q.front(); q.pop();
    int r = pos.first;
    int c = pos.second;
    int d = qd.front(); qd.pop();
    int k = qk.front(); qk.pop();
    //printf("r c k %d %d %d\n", r, c, k);

    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr >= 1 && nr <= M && nc >= 1 && nc <= N &&
          !visit[nr][nc] &&
          (field[nr][nc] == 0 || (field[nr][nc] == 1 && k < K))) {
        dist[nr][nc] = d + 1;
        visit[nr][nc] = 1;
        qd.push(d+1);
        q.push({nr, nc});
        if (field[nr][nc] == 1) {
          //printf("nr nc k+1 %d %d\n", nr, nc);
          qk.push(k+1);
        }
        else { // 缺了这个 else 导致了诡异的 bug
          qk.push(0);
        }
      }
    }
    //printf("%lu\n", (!q.empty()) ? q.size() : 0);
    //printf("1 %d\n", q.empty());
  }

  //print();
  if (dist[M][N] == INF) printf("-1\n");
  else printf("%d\n", dist[M][N]);
  //printf("end case\n");
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    input();
    solve();
    //printf("%d %d %d\n", M, N, dist[M][N]);
  }
  //printf("3\n");

  return 0;
}
