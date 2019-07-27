#include <stdio.h>

char c1[6];
char c2[6];
char temp[6];

int issame()
{
  /*
  for (int i = 0; i < 3; i++) {
    int eq1, eq2;
    eq1 = ((c1[i] == c2[i]) && (c1[6-i-1] == c2[6-i-1])) ? 1 : 0;
    eq2 = ((c1[i] == c2[6-i-1]) && (c1[6-i-1] == c2[i])) ? 1 : 0;
    if (!(eq1 || eq2)) {
      printf("0\n");
      return 0;
    }
  }

  return 1;
  */
  for (int i = 0; i < 6; i++) {
    if (c1[i] != c2[i]) return 0;
  }

  return 1;
}

int rotatedown()
{
  for (int i = 0; i < 6; i++) {
    temp[i] = c1[i];
  }
  c1[0] = temp[4];
  c1[1] = temp[0];
  c1[2] = temp[2];
  c1[3] = temp[3];
  c1[4] = temp[5];
  c1[5] = temp[1];

  return issame();
}

int rotateleft()
{
  for (int i = 0; i < 6; i++) {
    temp[i] = c1[i];
  }
  c1[0] = temp[0];
  c1[1] = temp[3];
  c1[2] = temp[1];
  c1[3] = temp[4];
  c1[4] = temp[2];
  c1[5] = temp[5];

  return issame();
}

int rotateright()
{
  for (int i = 0; i < 6; i++) {
    temp[i] = c1[i];
  }
  c1[0] = temp[0];
  c1[1] = temp[2];
  c1[2] = temp[4];
  c1[3] = temp[1];
  c1[4] = temp[3];
  c1[5] = temp[5];


  return issame();
}


int main()
{
  while (scanf("%6s%6s", c1, c2) == 2) {
    //printf("%6s %6s\n", c1, c2);
    int same = 0;
    if (issame()) same = 1;
    // down 3
    for(int i = 0; i < 3; i++) {
      if(rotatedown()) same = 1;
      for(int j = 0; j < 4; j++) {
        if(rotateleft()) same = 1;
      }
    }
    // left 1
    if (rotateleft()) same = 1;
    for(int i = 0; i < 4; i++) {
      if(rotateleft()) same = 1;
    }
    // right 1
    if (rotateright()) same = 1;
    for(int i = 0; i < 4; i++) {
      if(rotateleft()) same = 1;
    }

    if (same) printf("TRUE\n");
    else printf("FALSE\n");
  }
}
