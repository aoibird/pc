#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define flip(x) (((x) == 0) ? (1) : (-1))
using namespace std;

const int MAXN = 100+10;
int A[MAXN];
int S[MAXN];
int N;
int DP[MAXN][MAXN];

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    if (i == 0) S[0] = A[0];
    else S[i] = S[i-1] + A[i];
  }
  int s = S[N-1];


  DP[0][0] = s + flip(A[0]);
  int M = DP[0][0];
  for (int i = 1; i < N; i++) {
    DP[0][i] = DP[0][i-1] + flip(A[i]);
    DP[i][i] = s + flip(A[i]);
    M = max(M, max(DP[0][i], DP[i][i]));
  }

  for (int i = 1; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      DP[i][j] = DP[i][j-1] + flip(A[j]);
      M = max(DP[i][j], M);
    }
  }
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     printf("%d ", DP[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("%d\n", M);
}
