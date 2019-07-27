#include <stdio.h>
#include <string.h>
#define MAXM 1005
#define MAXN 1005

int m, n;
char matrix[MAXM][MAXN];

void input()
{
  scanf("%d%d", &m, &n);
  getchar();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char c = getchar();
      matrix[i][j] = c;
    }
    getchar();
  }
  /*
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c ", matrix[i][j]);
    }
    printf("\n");
  }
  */
}

void solve()
{
  // solve
  int a[4];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    memset(a, 0, sizeof(a));
    for (int j = 0; j < m; j++) {
      if (matrix[j][i] == 'A') a[0] += 1;
      else if (matrix[j][i] == 'C') a[1] += 1;
      else if (matrix[j][i] == 'G') a[2] += 1;
      else if (matrix[j][i] == 'T') a[3] += 1;
      else ;
    }

    int index = 0;
    for (int i = 0; i < 4; i++)
      if (a[i] > a[index]) index = i;

    if (index == 0) putchar('A');
    else if (index == 1) putchar('C');
    else if (index == 2) putchar('G');
    else if (index == 3) putchar('T');
    else ;

    cnt += (m - a[index]);
  }
  putchar('\n');

  printf("%d\n", cnt);

}

int main()
{
  int rnd;
  scanf("%d", &rnd); getchar();
  for (int i = 0; i < rnd; i++) {
    input();
    solve();
  }
}
