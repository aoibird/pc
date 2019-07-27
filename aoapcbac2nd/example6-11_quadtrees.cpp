#include <iostream>
#include <cstring>
#define LEN 32
#define MAXN 1034
using namespace std;

char s[MAXN];
int buff[LEN][LEN];
int cnt;

void draw(char *s, int& p, int r, int c, int w) {
  char ch = s[p++];
  if (ch == 'p') {
    draw(s, p, r, c+w/2, w/2);
    draw(s, p, r, c, w/2);
    draw(s, p, r+w/2, c, w/2);
    draw(s, p, r+w/2, c+w/2, w/2);
  }
  else if (ch == 'f') {
    for (int i = r; i < r+w; i++)
      for (int j = c; j < c+w; j++)
        if (buff[i][j] == 0) {
          buff[i][j] = 1;
          cnt++;
        }
  }
}

int main()
{
  int cas;
  scanf("%d", &cas);
  for (int i = 0; i < cas; i++) {
    memset(buff, 0, sizeof(buff));
    cnt = 0;
    for (int j = 0; j < 2; j++) {
      int p = 0;
      scanf("%s", s);
      draw(s, p, 0, 0, LEN);
    }

    printf("There are %d black pixels.\n", cnt);
  }
}
