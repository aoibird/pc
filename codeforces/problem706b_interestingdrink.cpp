#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000+10;
int S[MAXN];
int N;
int Q;

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &S[i]);

  sort(S, S+N);

  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    int x; scanf("%d", &x);
    int y = upper_bound(S, S+N, x) - S;
    printf("%d\n", y);
  }
}
