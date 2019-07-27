#include <stdio.h>

void solve()
{
  int c;
  int score = 0;
  int o = 0;
  while ((c = getchar()) != '\n') {
    if (c == 'O') {
      o += 1;
      score += o;
    }
    else if (c == 'X') {
      o = 0;
    }
    else {
      ;
    }
  }

  printf("%d\n", score);
}

int main()
{
  int rnd;
  scanf("%d", &rnd); getchar();
  for (int i = 0; i < rnd; i++) {
    solve();
  }

}
