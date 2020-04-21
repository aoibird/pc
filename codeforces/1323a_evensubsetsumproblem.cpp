#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100+10;
int A[MAXN];
int N;
bool odd;
int index_odd;

void solve()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  odd = false;
  for (int i = 0; i < N; i++) {
    if (A[i] % 2 == 0) { printf("1\n%d\n", i+1); return; }
    else if (odd == false) { odd = true; index_odd = i; }
    else { printf("2\n%d %d\n", index_odd+1, i+1); return; }
  }
  printf("-1\n");
}

int main()
{
  int TC; scanf("%d", &TC);
  for (int i = 0; i < TC; i++) {
    solve();
  }
}
