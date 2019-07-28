#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int MAXN = 505;

int W, H, N;
int X1[MAXN], X2[MAXN], Y1[MAXN], Y2[MAXN];
int field[MAXN * 6][MAXN * 6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int cnt;

void printfield()
{
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%d", field[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int compress(int *k1, int *k2, int n)
{
  vector<int> k;

  for (int i = 0; i < N; i++) {
    for (int d = -1; d <= 1; d++) {
      int tk1 = k1[i] + d, tk2 = k2[i] + d;
      // 与书上稍有不同，不知道有没有 bug
      if (1 <= tk1 && tk1 <= n && tk1 <= k1[i]) k.push_back(tk1);
      if (1 <= tk2 && tk2 <= n && tk2 >= k2[i]) k.push_back(tk2);
      //if (1 <= tk1 && tk1 <= n) k.push_back(tk1);
      //if (1 <= tk2 && tk2 <= n) k.push_back(tk2);
    }
  }

  for (int i = 0; i < k.size(); i++) {
    printf("%d ", k[i]);
  }
  printf("\n");

  sort(k.begin(), k.end());
  k.erase(unique(k.begin(), k.end()), k.end());

  for (int i = 0; i < N; i++) {
    k1[i] = find(k.begin(), k.end(), k1[i]) - k.begin();
    k2[i] = find(k.begin(), k.end(), k2[i]) - k.begin();
  }

  return k.size();
}

void input()
{
  scanf("%d%d%d", &W, &H, &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", X1+i);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", X2+i);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", Y1+i);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", Y2+i);
  }

}

void bfs(int y, int x)
{
  queue<P> q;
  q.push(P(x, y));
  while (!q.empty()) {
    P s = q.front(); q.pop();
    int sx = s.first, sy = s.second;

    for (int i = 0; i < 4; i++) {
      int tx = sx + dx[i], ty = sy + dy[i];
      if (tx >= 0 && tx < W && ty >= 0 && ty < H &&
          field[ty][tx] == 0) {
        q.push(P(tx, ty));
        field[ty][tx] = 1;
      }
    }
  }
}

void solve()
{
  W = compress(X1, X2, W);
  H = compress(Y1, Y2, H);

  for (int i = 0; i < N; i++) {
    for (int y = Y1[i]; y <= Y2[i]; y++) {
      for (int x = X1[i]; x <= X2[i]; x++) {
        field[y][x] = 1;
      }
    }
  }

  printfield();

  cnt = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (field[y][x] == 0) {
        bfs(y, x);
        cnt++;
      }
    }
  }

  printf("%d\n", cnt);
}

int main()
{
  input();
  solve();
}
