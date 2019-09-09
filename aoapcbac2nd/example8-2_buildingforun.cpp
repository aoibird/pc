// UVa 1605
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

int main()
{
  int c[52];
  for (int i = 0; i < 26; i++) { c[i*2] = i+'A'; c[i*2+1] = i+'a'; }
  // for (int i = 0; i < 52; i++) printf("%c", c[i]);
  // printf("\n");
  while (scanf("%d", &N) == 1) {
    printf("%d %d %d\n", 2, N, N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%c", c[i]);
      }
      printf("\n");
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%c", c[j]);
      }
      printf("\n");
    }
    printf("\n");
  }
}
