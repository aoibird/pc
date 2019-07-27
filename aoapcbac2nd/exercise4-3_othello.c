#include <stdio.h>


char board[9][9]; // start from 1, 8x8
char curr; // current player
int instr;
int row, col;
int d1[8] = {1, -1, 1, -1, 1, -1, 0, 0};
int d2[8] = {1, -1, -1, 1, 0, 0, -1, 1};

void trace()
{
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
  printf("%c\n", curr);
}

void getboard()
{
  //printf("!!!!\n");
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      board[i][j] = getchar();
    }
    getchar();
  }
  curr = getchar(); getchar();

  //trace();
}

int getinstr()
{
  instr = getchar();
  if (instr == 'M') {
    row = getchar() - '0';
    col = getchar() - '0';
  }
  getchar();

  if (instr == 'L' || instr == 'M') return 1;
  else return 0;
}

int valid(int x, int y)
{
  if (board[x][y] != '-') return -1;

  for (int k = 0; k < 8; k++) { // all directions
    int dx = d1[k];
    int dy = d2[k];
    int i, j;
    for (i = x+dx, j = y+dy; i >= 1 && i <= 8 && j >= 1 && j <= 8; i+=dx, j+=dy) {
      if (board[i][j] == '-' || board[i][j] == curr) break;
    }

    if (board[i][j] == curr && (i != x+dx || j != y+dy)) {
      //printf("found: %c %d %d\n", board[i][j], i, j);
      return 1;
    }
  }

  return 0;
}

void changecolor(int x, int y)
{
  for (int k = 0; k < 8; k++) {
    int dx = d1[k];
    int dy = d2[k];
    int i, j;
    for (i = x+dx, j = y+dy; i >= 1 && i <= 8 && j >= 1 && j <= 8; i+=dx, j+=dy) {
      if (board[i][j] == '-' || board[i][j] == curr) break;
    }

    if (board[i][j] == curr && (i != x+dx || j != y+dy)) {
      for (i = x+dx, j = y+dy; i >= 1 && i <= 8 && j >= 1 && j <= 8; i+=dx, j+=dy) {
        if (board[i][j] == curr) break;
        board[i][j] = curr;
      }
    }
  }
}

void countboard(int *b, int *w)
{
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (board[i][j] == 'B') {
        *b += 1;
      }
      else if (board[i][j] == 'W') {
        *w += 1;
      }
      else {
        ;
      }
    }
  }

}

void execute()
{
  if (instr == 'L') {
    int first = 1;
    int exist = 0;
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++) {
        if (valid(i, j) == 1) {
          if (first) first = 0;
          else printf(" ");

          printf("(%d,%d)", i, j);
          exist = 1;
        }
      }
    }

    if (!exist) {
      printf("No legal move.");
      curr = (curr == 'W') ? 'B' : 'W';
    }

    printf("\n");
  }
  else if (instr == 'M') {
    board[row][col] = curr;
    //printf("change color %d %d\n", row, col);
    changecolor(row, col);
    int b = 0, w = 0;
    countboard(&b, &w);
    printf("Black - %2d White - %2d\n", b, w);
    curr = (curr == 'W') ? 'B' : 'W';
  }
  else {
    ;
  }
}

void printboard()
{
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}


int main()
{
  int rnd;
  scanf("%d", &rnd); getchar();
  for (int i = 0; i < rnd; i++) {
    if (i != 0) printf("\n");
    getboard();
    while (getinstr()) {
      //printf("instr: %c\n", instr);
      execute();
      //trace();
    }
    printboard();
    //printf("\n");
  }
}
