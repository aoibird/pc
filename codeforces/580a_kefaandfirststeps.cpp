#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000+10;
int A[MAXN];
int N;
int CNT[MAXN];

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  CNT[0] = 1;
  int M = 1;
  for (int i = 1; i < N; i++) {
    if (A[i-1] <= A[i]) CNT[i] = CNT[i-1] + 1;
    else CNT[i] = 1;

    M = max(M, CNT[i]);
  }
  // for (int i = 0; i < N; i++) printf("%d%c", CNT[i], i==N-1?'\n':' ');
  printf("%d\n", M);
}
