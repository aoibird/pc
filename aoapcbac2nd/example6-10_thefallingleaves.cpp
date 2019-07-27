#include <iostream>
#include <cstring>
#define MAXW 200
#define MAXC 400
using namespace std;

int sum[MAXW];
int first, finish;

void solve(int h, int w)
{
  int value = 0;
  scanf("%d", &value);
  //printf("%d\n", value);
  if (value == -1) {
    if (first) finish = 1;
    return;
  }
  first = 0;

  sum[w] += value;

  solve(h+1, w-1);
  solve(h+1, w+1);
}

void printsum()
{
  int first = 1;
  for (int col = 0; col < MAXW; col++) {
    if (sum[col] == 0) continue;

    if (first) first = 0;
    else printf(" ");

    printf("%d", sum[col]);
  }
  printf("\n");
}

int main()
{
  int c, rnd = 0;
  while ((c = getchar()) != EOF) {
    ungetc(c, stdin);

    memset(sum, 0, sizeof(sum));
    first = 1, finish = 0;
    solve(0, MAXW/2);
    if (finish) break;

    printf("Case %d:\n", rnd+1);
    printsum();
    printf("\n");

    rnd++;
  }

}
