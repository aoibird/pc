#include <stdio.h>
#include <string.h>
#define MAXS 1000

char str1[MAXS];
char str2[MAXS];
int rest;
int chance;
int win, lose;

void guess(char ch)
{
  int bad = 1;
  for (int i = 0; str1[i] != '\0'; i++) {
    if (str1[i] == ch) {
      rest -= 1;
      str1[i] = ' ';
      bad = 0;
    }
  }

  if (bad) chance -= 1;
  if (chance == 0) lose = 1;
  if (rest == 0) win = 1;
}

int main()
{
  int rnd;
  while (scanf("%d%s%s", &rnd, str1, str2) == 3 && rnd != -1) {
    printf("Round %d\n", rnd);
    win = 0, lose = 0, chance = 7, rest = strlen(str1);

    int i, j;
    for (i = 0; str2[i] != '\0'; i++) { // guessed character
      guess(str2[i]);

      if (win || lose) break;
    }

    if (lose) {
      printf("You lose.\n");
    }
    else if (win) {
      printf("You win.\n");
    }
    else {
      printf("You chickened out.\n");
    }
  }

}
