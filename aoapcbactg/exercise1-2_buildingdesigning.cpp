// UVa 11039
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 500000;
int A[MAXN];
int N; // [1, 5_00_000]

bool abscomp(int& a, int &b)
{
  if (abs(a) < abs(b)) return true;
  else return false;
}

int main()
{
  int tc;
  scanf("%d", &tc);
  for (int i = 0; i < tc; i++) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", A+i);

    sort(A, A+N, abscomp);
    int cnt = 1;
    for (int i = 1; i < N; i++) {
      if (A[i] * A[i-1] < 0) cnt++;
    }

    printf("%d\n", cnt);
  }
}
