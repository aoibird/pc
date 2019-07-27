#include <stdio.h>
#include <math.h>
#define MAXL 100
#define MAXS 1000

char header[MAXL][MAXS];
int height = 0;

void getheader()
{
  int c;
  for (int i = 1, width = 2; c != '\n'; i++, width *= 2) {
    height = i;
    //printf("%d %d\n", height, width);
    for (int j = 0; j < width - 1; j++) {
      c = getchar();
      //printf("%d %d %c ", i, j, c);
      if (c == '\n') break;
      header[i][j] = c;
    }
    //printf("\n");
  }
  //height = i - 1;
  /*
  for (int i = 1, width = 2; i < height + 1; i++, width *= 2) {
    for (int j = 0; j < width - 1; j++) {
      printf("%c ", header[i][j]);
    }
    printf("\n");
  }
  */
}

int getlength()
{
  int c, len = 0;
  for (int i = 0; i < 3; i++) {
    while ((c = getchar()) == '\n') ;
    if (c == EOF) return 0;
    len <<= 1;
    len += (c - '0');
  }

  return len;
}

void getbody(int len)
{
  int c;
  while (1) {
    int value = 0;
    for (int i = 0; i < len; i++) {
      while ((c = getchar()) == '\n');
      if (c == EOF) return;
      value = value << 1;
      value += (char) c - '0';
    }

    if (value == pow(2, len) - 1) break;

    putchar(header[len][value]);
  }
}

void solve()
{
  getheader();
  while (1) {
    int len = getlength(); // 3 characters
    if (len == 0) {
      getchar();
      break;
    }
    getbody(len);
  }
  printf("\n");
}


int main()
{
  int c;
  while ((c = getchar()) != EOF) {
    ungetc(c, stdin);
    solve();
  }

}
