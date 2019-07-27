#include <iostream>
#include <cstdio>
#include <cctype>
#define MAXR 205
#define MAXC 205
using namespace std;

char pad[MAXR][MAXC];

int islabel(char ch)
{
  if (isprint(ch) && ch != '-' &&
      ch != '|' && ch != ' ' && ch != '#') return 1;
  else return 0;
}

void printpad()
{
  for (int r = 0; pad[r][0] != '\0'; r++) {
    for (int c = 0; pad[r][c] != '\0'; c++) {
      printf("%c", pad[r][c]);
    }
    printf("\n");
  }
}

void input()
{
  for (int r = 0; ; r++) {
    //printf("r = %d\n", r);
    int ch;
    int c = 0;
    while ((ch = getchar()) != '\n') pad[r][c++] = ch;
    if (pad[r][0] == '#') {
      pad[r][0] = '\0';
      break;
    }
    else pad[r][c] = '\0';
    //printf("c = %d\n", c);
  }

  //printpad();
}


void solve(int r, int c)
{
  printf("%c(", pad[r][c]);

  if (pad[r+1][c] == '|') {
    int left = c, right = c;
    while (left >= 0 && pad[r+2][left] == '-') left--;
    while (pad[r+2][right] == '-') right++;
    left++; right--;
    for (int i = left; i <= right; i++) {
      if (islabel(pad[r+3][i])) solve(r+3, i);
    }
  }

  printf(")");
}

int main()
{
  int T;
  scanf("%d", &T); getchar();
  for (int i = 0; i < T; i++) {
    printf("Case %d:\n", i+1);
    input();
    int c = 0;
    while (!islabel(pad[0][c])) c++;
    printf("(");
    solve(0, c);
    printf(")\n");
  }

}
