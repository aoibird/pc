#include <stdio.h>
#include <string.h>
#define MAXM 1005 // the max number of addresses

int ipa[MAXM][32];
int m;
int mask[32];
int neta[32];

void trace()
{
  for (int i = 0; i < m; i++) {
    printf("%4d: ", i);
    for (int j = 31; j >= 0; j--) {
      printf("%d", ipa[i][j]);
    }
    printf("\n");
  }
  printf("mask: ");
  for (int j = 31; j >= 0; j--) {
    printf("%d", mask[j]);
  }
  printf("\n");
  printf("neta: ");
  for (int j = 31; j >= 0; j--) {
    printf("%d", neta[j]);
  }
  printf("\n");
}

void input()
{
  scanf("%d", &m);
  memset(ipa, 0, sizeof(ipa));


  for (int i = 0; i < m; i++) {
    int b1, b2, b3, b4;
    scanf("%d.%d.%d.%d", &b1, &b2, &b3, &b4);
    //printf("%d.%d.%d.%d\n", b1, b2, b3, b4);
    for (int j = 0; j < 8; j++) {
      //printf("%d, %d, %d, %d\n",);
      ipa[i][j] = b4 % 2;
      ipa[i][j+8] = b3 % 2;
      ipa[i][j+16] = b2 % 2;
      ipa[i][j+24] = b1 % 2;
      b4 = b4 / 2;
      b3 = b3 / 2;
      b2 = b2 / 2;
      b1 = b1 / 2;
    }
  }

}

void solve()
{

  for (int i = 31; i >= 0; i--) {
    int eq = 1;
    for (int j = 1; j < m; j++) {
      if (ipa[0][i] != ipa[j][i]) eq = 0;
    }


    if (eq == 1) {
      if (i != 0) {
        mask[i] = 1;
        neta[i] = ipa[0][i];
      }
      else {
        mask[i] = 0;
        neta[i] = 0;
      }
    }
    else {
      break;
    }
  }
}

void output()
{
  int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  for (int j = 0, w = 1; j < 8; j++, w *= 2) {
    b4 += neta[j] * w;
    b3 += neta[j+8] * w;
    b2 += neta[j+16] * w;
    b1 += neta[j+24] * w;
  }
  printf("%d.%d.%d.%d\n", b1, b2, b3, b4);

  b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  for (int j = 0, w = 1; j < 8; j++, w *= 2) {
    b4 += mask[j] * w;
    b3 += mask[j+8] * w;
    b2 += mask[j+16] * w;
    b1 += mask[j+24] * w;
  }
  printf("%d.%d.%d.%d\n", b1, b2, b3, b4);

}

int main()
{
  input();
  solve();
  trace();
  output();
}
