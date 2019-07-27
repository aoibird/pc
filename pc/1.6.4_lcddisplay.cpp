#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define VERT 1
#define HOR 0
using namespace std;
const int MAXN = 8+2;
const int MAXS = 10+5;
const int MAXR = 2*MAXS+3;
const int MAXC = MAXN*(MAXS+2);

int S; // [1, 10] size
int N; // [0, 9999 9999] number
int digits[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                     {0, 1, 1, 0, 0, 0, 0},
                     {1, 1, 0, 1, 1, 0, 1},
                     {1, 1, 1, 1, 0, 0, 1},
                     {0, 1, 1, 0, 0, 1, 1},
                     {1, 0, 1, 1, 0, 1, 1},
                     {1, 0, 1, 1, 1, 1, 1},
                     {1, 1, 1, 0, 0, 0, 0},
                     {1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 0, 1, 1}};
int segs[7][3] = {{HOR, 0, 0}, {VERT, 0, 1}, {VERT, 1, 1}, {HOR, 2, 0},
                  {VERT, 1, 0}, {VERT, 0, 0}, {HOR, 1, 0}};
int pad[MAXR][MAXC];
int R, C;

void draw(char s, int pos)
{
  // for each segments draw it on pad
  //printf("%d\n", s-'0');
  for (int i = 0; i < 7; i++) {
    if (digits[s-'0'][i] == 1) {
      // draw the segment
      int r = segs[i][1] * (S+1);
      int c = pos + segs[i][2] * (S+1);
      //printf("%d %d\n", r, c);
      if (segs[i][0] == HOR) {
        for (int i = 0; i < S; i++) pad[r][c+1+i] = '-';
      }
      else if (segs[i][0] == VERT) {
        for (int i = 0; i < S; i++) pad[r+1+i][c] = '|';
      }
      else ;
    }
  }
}

void print()
{
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%c", pad[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int first = 1;
  while (scanf("%d", &S) == 1) {
    if (S == 0) break;
    // init
    char liter[MAXN];
    int c = getchar();
    int i = 0;
    while (isdigit(c = getchar())) liter[i++] = c;
    liter[i] = '\0';

    R = 2*S+3;
    C = strlen(liter)*(S+2);
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        pad[i][j] = ' ';
      }
    }
    // for each digits draw it on pad
    for (int i = 0; liter[i] != '\0'; i++) {
      int pos = i * (S + 2);
      draw(liter[i], pos);
      //print();
    }

    if (first == 1) first = 0;
    else printf("\n");
    print();
  }
}
