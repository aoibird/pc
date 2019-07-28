#include <iostream>
using namespace std;
const int N = 6;

int P[N];
int M[N] = {1, 4, 9, 16, 25, 36};

int main()
{

  while (scanf("%d%d%d%d%d%d", P, P+1, P+2, P+3, P+4, P+5) == 6) {
    if (P[0] == 0 && P[1] == 0 && P[2] == 0 &&
        P[3] == 0 && P[4] == 0 && P[5] == 0) break;

    /*
    printf("###\n");
    int cnt = 0;
    int ok = 0;
    while (!ok) {
      int rest = 36;
      ok = 1;
      for (int i = N-1; i >= 0; i--) {
        while (P[i] > 0 && rest - M[i] >= 0) {
          rest -= M[i];
          P[i] -= 1;
        }

        if (P[i] != 0) ok = 0;
      }
      cnt++;

      // for (int i = 0; i < N; i++) {
      //   printf("%d ", P[i]);
      // }
      // printf("\n");
    }

    printf("%d\n", cnt);
    */
    int cnt = 0;
    while (P[5] != 0) { // 6*6
      P[5] -= 1;
      cnt++;
    }
    while (P[4] != 0) { // 5*5
      P[4] -= 1;
      if (P[0] > 11) P[0] -= 11;
      else if (P[0] > 0) P[0] = 0;
      else ;
      cnt++;
    }
    while (P[3] != 0) { // 4*4
      P[3] -= 1;
      if (P[1] > 5) P[1] -= 5;
      else if (P[1] > 0) {
        int rest = 5 - P[1];
        P[1] = 0;
        P[0] = (P[0] > rest * 4) ? P[0]-rest*4 : 0;
      }
      else {
        P[0] = (P[0] > 20) ? P[0] - 20 : 0;
      }

      cnt++;
    }
    while (P[2] != 0) {
      if (P[2] >= 4) {
        P[2] -= 4;
      }
      else if (P[2] == 3) {
        P[2] = 0;
        if (P[1] >= 1) {
          P[1] -= 1;
          P[0] = (P[0] > 5) ? P[0] - 5 : 0;
        }
        else {
          P[0] = (P[0] > 9) ? P[0] - 9 : 0;
        }
      }
      else if (P[2] == 2) {
        P[2] = 0;
        if (P[1] >= 3) {
          P[1] -= 3;
          P[0] = (P[0] > 6) ? P[0] - 6 : 0;
        }
        else {
          int rest = 3 - P[1];
          P[1] = 0;
          P[0] = (P[0] > rest*4) ? P[0] - rest*4 : 0;
        }
      }
      else if (P[2] == 1) {
        P[2] = 0;
        if (P[1] >= 5) {
          P[1] -= 5;
          P[0] = (P[0] > 7) ? P[0] - 7 : 0;
        }
        else {
          int rest = 5 - P[1];
          P[1] = 0;
          P[0] = (P[0] > rest*4) ? P[0] - rest*4 : 0;
        }
      }
      else ;

      cnt++;
    }
    while (P[1] != 0) {
      if (P[1] >= 9) {
        P[1] -= 9;
      }
      else {
        int rest = 9 - P[1];
        P[1] = 0;
        P[0] = (P[0] > rest*4) ? P[0] - rest*4 : 0;
      }
      cnt++;
    }
    while (P[0] != 0) {
      P[0] = (P[0] > 36) ? P[0] - 36 : 0;
      cnt++;
    }

    printf("%d\n", cnt);
  }
}
