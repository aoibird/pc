#include <stdio.h>
#include <string.h>
#define MAXN 25

int out[MAXN];
int n, k, m;

int go(int p, int d, int s)
{
  int i = 0;
  while (1) {
    if (out[p] == 0) {
      i++;
    }
    if (i == s) break;
    p = (p + d + n) % n;
    //printf("%d %d\n", p, i);

  }

  return p;
}

void solve()
{
  int rest = n;
  int p1 = 0;
  int p2 = n-1;
  memset(out, 0, sizeof(out));
  while (rest > 0) {
    p1 = go(p1, 1, k);
    p2 = go(p2, -1, m);

    if (p1 == p2) {
      rest -= 1;
      out[p1] = 1;
      printf("%3d", p1+1);
    }
    else {
      rest -= 2;
      out[p1] = 1;
      out[p2] = 1;
      printf("%3d", p1+1);
      printf("%3d", p2+1);
    }

    if (rest != 0) printf(",");
  }
  printf("\n");
}


int main()
{
  while (scanf("%d%d%d", &n, &k, &m) == 3 &&
         n && k && m) {
    solve();
  }

}
