#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int R = 8;
const int C = 8;
char board[R][C];
int kr, kc; // black
int Kr, Kc; // white

int knight_dr[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int knight_dc[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

int input()
{
  kr = kc = -1;
  Kr = Kc = -1;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      board[r][c] = getchar();
      if (board[r][c] == 'k') { kr = r; kc = c; }
      if (board[r][c] == 'K') { Kr = r; Kc = c; }
    }
    getchar();
  }

  if (Kr == -1 && Kc == -1) return 1; // empty
  else return 0;
}

int check_dial(int r, int c, int kr, int kc)
{
  int dr = (kr < r) ? -1 : 1;
  int dc = (kc < c) ? -1 : 1;
  //printf("(%d,%d)", dr, dc);
  for (int x = r+dr, y = c+dc; x != kr && y != kc; x += dr, y += dc) {
    //printf("%c", board[x][y]);
    if (board[x][y] != '.') return 0;
  }

  return 1;
}

int check_row(int r, int c, int kr, int kc) // r == kr
{
  int d = (kc < c) ? -1 : 1;
  //printf("(%d)", d);
  for (int x = c+d; x != kc; x += d)
    if (board[r][x] != '.') return 0;
  return 1;
}

int check_col(int r, int c, int kr, int kc) // c == kc
{
  int d = (kr < r) ? -1 : 1;
  //printf("(%d)", d);
  for (int x = r+d; x != kr; x += d)
    if (board[x][c] != '.') return 0;
  return 1;
}

int check(char p, int r, int c, int kr, int kc)
{
  // for different pieces check if it can check king
  char t = tolower(p);
  if (p == 'p') { // Pawn black down
    if ((kr == r+1 && kc == c-1) || (kr == r+1 && kc == c+1)) return 1;
    else return 0;
  }
  else if (p == 'P') { // Pawn white up
    if ((kr == r-1 && kc == c-1) || (kr == r-1 && kc == c+1)) return 1;
    else return 0;
  }
  else if (t == 'r') { // Rook
    if (kr == r) return check_row(r, c, kr, kc);
    else if (kc == c) return check_col(r, c, kr, kc);
    else return 0; // can not reach
  }
  else if (t == 'b') { // Bishop
    if ((r+c == kr+kc) || (kr-r==kc-c)) return check_dial(r, c, kr, kc);
    else return 0;
  }
  else if (t == 'q') { // Queen
    //printf("(%d,%d)->(%d,%d)", r, c, kr, kc);
    if (r == kr) return check_row(r, c, kr, kc);
    else if (c == kc) return check_col(r, c, kr, kc);
    else if ((r+c == kr+kc) || (kr-r==kc-c)) return check_dial(r, c, kr, kc);
    else return 0;
  }
  else if (t == 'k') { // King
    for (int dr = -1; dr <= 1; dr++) {
      for (int dc = -1; dc <= 1; dc++) {
        if (r+dr == kr && c+dc == kc) return 1;
      }
    }
    return 0;
  }
  else if (t == 'n') { // Knight
    for (int i = 0; i < 8; i++) {
      int nr = knight_dr[i] + r;
      int nc = knight_dc[i] + c;
      if (nr == kr && nc == kc) return 1;
    }
    return 0;
  }
  else return 0;
}

void solve()
{
  int w = 0, b = 0;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (board[r][c] != '.' && isupper(board[r][c]))
        w = check(board[r][c], r, c, kr, kc); // white piece checks black king 'k'
      else if (board[r][c] != '.' && islower(board[r][c]))
        b = check(board[r][c], r, c, Kr, Kc); // black piece checks white king 'K'

      //printf("%c(%d|%d) ", board[r][c], w, b);
      if (w || b) break;
    }
    if (w || b) break;
    //printf("\n");
  }
  //printf("\n");

  if (w) printf("black king is in check.\n"); // white piece checks black king
  else if (b) printf("white king is in check.\n");
  else printf("no king is in check.\n");
}



int main()
{
  int rnd = 1;
  while (1) {
    if (rnd != 1) getchar();
    int empty = input();
    if (empty) break;

    printf("Game #%d: ", rnd);
    solve();

    rnd++;
  }
}
