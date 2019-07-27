#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXS 85
#define MAXW 105

char table[36][10];
char context[MAXW][MAXS];
int nw;
char contmorse[MAXW][MAXS];
char morse[MAXS];


void printtable()
{
  for (int i = 0; i < 36; i++) {
    printf("%s\n", table[i]);
  }
}

void gettable()
{
  int c;
  char buff[MAXS];
  while ((c = getchar()) != '*') {
    scanf("%s", buff);
    if (isdigit(c)) strcpy(table[c-'0'], buff);
    else strcpy(table[c-'A'+10], buff);
    //printf("%s\n", buff);
    getchar();
  }
}

void getcont()
{
  char buff[MAXS];
  nw = 0;
  while (scanf("%s", buff) == 1) {
    if (buff[0] == '*') break;

    strcpy(context[nw], buff);
    nw++;
  }

  for (int i = 0; i < nw; i++) {
    int len = 0;
    for (int j = 0; context[i][j] != '\0'; j++) {
      int c = context[i][j];
      sprintf(buff, "%s", (isdigit(c) ? table[c-'0'] : table[c-'A'+10]));
      for (int k = 0; buff[k] != '\0'; k++) {
        contmorse[i][len++] = buff[k];
      }
    }
    contmorse[i][len++] = '\0';
  }

  /*
  for (int i = 0; i < nw; i++) {
    printf("%s\n", context[i]);
    printf("%s\n", contmorse[i]);
  }
  */
}

void iserror(char *word, int x, int *lprefix, int *fextra, int *lindex, int *findex)
{
  char *s = word;
  char *t = contmorse[x];
  int i = 0, nc = 0;
  while (s[i] != '\0' && t[i] != '\0') {
    if (s[i] == t[i]) nc++;
    else break;
    i++;
  }

  if (t[i] == '\0') {
    if (strlen(contmorse[x]) - nc < *fextra) {
      *findex = x;
      *fextra = strlen(contmorse[x]) - nc;
    }
  }
  else if (s[i] == '\0') {
    if (i > *lprefix) {
      *lindex = x;
      *lprefix = nc;
    }
  }
  else {
    ;
  }

}

void decode()
{
  char word[MAXS];
  while (scanf("%s", word) == 1) {
    if (word[0] == '*') break;

    //printf("%s\n", word);

    // walk through all context words
    int matches = 0, mindex = 0;
    int lprefix = -1, fextra = -1, lindex = -1, findex = -1;
    for (int i = 0; i < nw; i++) {
      //printf("%d %s\n", i, contmorse[i]);
      // if matched
      if (strcmp(word, contmorse[i]) == 0) { // !
        matches += 1;
        if (matches == 1) mindex = i;
      }
      //int *lprefix, int fextra, int *lindex, int *findex
      else { // ?
        iserror(word, i, &lprefix, &fextra, &lindex, &findex);
      }
    }

    //printf("matches = %d (%d %d %d %d)\n", matches, lprefix, lindex, fextra, findex);
    if (matches > 1) {
      printf("%s!\n", context[mindex]);
    }
    else if (matches == 1) {
      printf("%s\n", context[mindex]);
    }
    else { // matches == 0
      if (lindex != -1) {
        printf("%s?\n", context[lindex]);
      }
      else if (findex != -1) {
        printf("%s?\n", context[findex]);
      }
      else {
        ;
      }
    }

  }
}

int main()
{
  gettable();
  //printtable();
  getcont();
  decode();

}
