#include <stdio.h>
#include <string.h>
#define MAXN 15

int matrix[MAXN*MAXN][MAXN*MAXN];
int cnt[MAXN];
int n, m;

int walk(int s, int l)
{
  int p1 = s, p2 = s;
  //printf("l: %d\n", l);
  for (int i = 0; i < l; i++) {
    //printf("%d %d\n", p1, p2);
    if (matrix[p1][p1+n] != 1) return 0;
    else p1 = p1+n;

    if (matrix[p2][p2+1] != 1) return 0;
    else p2 = p2+1;
  }

  for (int i = 0; i < l; i++) {
    //printf("%d %d\n", p1, p2);
    if (matrix[p1][p1+1] != 1) return 0;
    else p1 = p1+1;

    if (matrix[p2][p2+n] != 1) return 0;
    else p2 = p2+n;
  }

  return 1;
}


void trace()
{
  for (int i = 1; i <= n*n; i++) {
    for (int j = 1; j <= n*n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void input()
{
  memset(matrix, 0, sizeof(matrix));
  memset(cnt, 0, sizeof(cnt));
  char ch;
  int px, py;
  for(int i = 0; i < m; i++) {
    scanf("%c%d%d", &ch, &px, &py);
    int from;
    if (ch == 'H') {
      from = (px-1) * n + py;
      matrix[from][from+1] = 1;
      matrix[from+1][from] = 1;
    }
    else if (ch == 'V') {
      from = (py-1) * n + px;
      matrix[from][from+n] = 1;
      matrix[from+n][from] = 1;
    }
    else ;
    getchar();
  }

  //trace();
}

void solve()
{
  for (int l = 1; l <= n-1; l++) {
    for (int sx = 1; sx <= n-l; sx++) {
      for (int sy = 1; sy <= n-l; sy++) {
        //printf("walk: start %d length %d\n", (sx-1)*n+sy, l);
        if (walk((sx-1)*n+sy, l)) {
          cnt[l] += 1;
          //printf("+1\n");
        }

      }
    }
  }
}

void output()
{
  int none = 1;
  for (int i = 1; i <= n - 1; i++) {
    if (cnt[i] != 0) {
      printf("%d square (s) of size %d\n", cnt[i], i);
      none = 0;
    }
  }

  if (none) printf("No completed squares can be found.\n");
}

int main()
{
  int rnd = 1, first = 1;
  while (scanf("%d%d", &n, &m) == 2) {
    if (first == 1) first = 0;
    else printf("\n**********************************\n\n");

    printf("Problem #%d\n\n", rnd);
    //printf("n,m: %d %d\n", n, m);
    getchar();
    input();
    solve();
    output();

    rnd++;
  }



}
