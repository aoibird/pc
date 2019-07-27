#include <stdio.h>
#include <ctype.h>

void solve()
{
  int c;
  double sum = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
    //printf("%c\n", c);
    int t;
    int cx = getchar();
    ungetc(cx, stdin);
    if (!isdigit(cx)) {
      t = 1;
    }
    else {
      scanf("%d", &t);
      //printf("%d", t);
    }

    if (c == 'C') {
      sum += (t * 12.01);
    }
    else if (c == 'H') {
      sum += (t * 1.008);
    }
    else if (c == 'O') {
      sum += (t * 16.00);
    }
    else if (c == 'N') {
      sum += (t * 14.01);
    }
    else {
      ;
    }
  }

  printf("%.3f\n", sum);

}

int main()
{
  int rnd;
  scanf("%d", &rnd); getchar();
  for (int i = 0; i < rnd; i++) {
    solve();
  }
}
