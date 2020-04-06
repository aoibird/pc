#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


const int MAXL = 20+5;
char S1[MAXL];
char S2[MAXL];
char table[3][9];

bool neighbor(char a, char b)
{
  int ra = (a-'a') / 9;
  int ca = (a-'a') % 9;
  int rb = (b-'a') / 9;
  int cb = (b-'a') % 9;
  if (ra-rb >= -1 && ra-rb <= 1 && ca-cb >= -1 && ca-cb <= 1)
    return true;
  else
    return false;
}


int main()
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 9; j++) {
      table[i][j] = 'a' + 9*i + j;
    }
  }

  int T;

  scanf("%d", &T); getchar();
  for (int t = 0; t < T; t++) {
    scanf("%s %s", S1, S2);

    int type = 1;
    int i;
    for (i = 0; S1[i] != '\0' && S2[i] != '\0'; i++) {
      if (S1[i] != S2[i]) {
        if (neighbor(S1[i], S2[i])) type = 2;
        else { type = 3; break; }
      }
    }
    if (S1[i] != S2[i]) { type = 3; }

    printf("%d\n", type);
  }
}
