#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000+10;
char S[MAXN];
int DP[MAXN];
int N, Q;

int main()
{
  scanf("%s", S+1);
  N = strlen(S+1);
  scanf("%d", &Q);

  // printf("%d\n", N);
  DP[1] = 0;
  for (int i = 2; i <= N; i++) {
    DP[i] = DP[i-1] + ((S[i-1] == S[i]) ? 1 : 0);
  }
  // for (int i = 1; i <= N; i++) {
  //   printf("%d%c", DP[i], i==N?'\n':' ');
  // }

  for (int i = 0; i < Q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", DP[b]-DP[a]);
  }
}
