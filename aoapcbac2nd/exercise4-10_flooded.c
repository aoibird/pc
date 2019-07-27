#include <stdio.h>
#include <stdlib.h>
#define MAXN 35
#define MAXM 35

int region[MAXM*MAXN];
int m, n;
int water;
double level;
double percent;

void trace()
{
  for (int i = 0; i < m*n; i++) {
    printf("%d ", region[i]);
  }
  printf("\n");
}

int compare(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

void solve()
{
  //trace();
  qsort(region, m*n, sizeof(int), compare);
  //trace();
  int sum = 0, nunit = 0;
  int i;
  for (i = 1; i < m*n; i++) {
    int x = sum + (region[i] - region[i-1])*100*i;
    if (x < water) {
      nunit += 1;
      sum = x;
    }
    else {
      break;
    }
  }
  int rest = water - sum;
  //printf("rest: %d nunit: %d i: %d\n", rest, nunit, i);

  if (rest == 0) {
    level = region[nunit];
    percent = ((double)nunit / (m*n)) * 100;
  }
  else {
    level = region[nunit] + (rest / ((nunit + 1.0) * 100));
    percent = ((nunit+1.0) / (m*n)) * 100;
  }
}

int main()
{
  int rnd = 1;
  while (scanf("%d%d", &m, &n) == 2 && m && n) {
    for (int i = 0; i < m*n; i++) {
      scanf("%d", &region[i]);
    }
    scanf("%d", &water);
    solve();
    printf("Region %d\n", rnd);
    printf("Water level is %.2f meters.\n", level);
    printf("%.2f percent of the region is under water.\n\n", percent);

    rnd++;
  }

}
