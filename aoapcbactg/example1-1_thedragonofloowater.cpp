#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define IMP -1
using namespace std;

const int MAXN = 20000;
const int MAXM = 20000;
int D[MAXN];
int K[MAXM];
int N; // [1, 20000]
int M; // [1, 20000]

void input()
{
  for (int i = 0; i < N; i++) scanf("%d", D+i);
  for (int i = 0; i < M; i++) scanf("%d", K+i);
}

int solve()
{
  sort(D, D+N);
  sort(K, K+M);

  int sum = 0;
  int j = 0;
  for (int i = 0; i < M; i++) {
    if (K[i] >= D[j]) { // Knight #i
      j++;
      sum += K[i];
    }

    if (j >= N) break;
  }
  if (j == N) return sum;
  else return IMP;
}

int main()
{
  while (scanf("%d%d", &N, &M) == 2) {
    if (N == 0 && M == 0) break;
    input();

    int cost = solve();

    if (cost == IMP) printf("Loowater is doomed!\n");
    else printf("%d\n", cost);
  }
}
