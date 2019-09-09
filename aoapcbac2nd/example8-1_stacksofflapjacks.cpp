// UVa 120
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 30; // [1, 30]
int P[MAXN+10]; // P[i] ~ [1, 100]
int N;

bool compare(int a, int b)
{
  if (a > b) return true;
  else return false;
}

void flip(int pos)
{
  for (int i = pos; i < (pos+N)/2; i++) {
    swap(P[i], P[pos+N-1-i]);
  }
}

void solve()
{
  int sorted[MAXN+10];
  for (int i = 0; i < N; i++) sorted[i] = P[i];
  sort(sorted, sorted+N, compare);
  flip(0);

  for (int i = 0; i < N; i++) {
    // check
    if (P[i] == sorted[i]) continue;

    // find
    int target = sorted[i];
    int pos = 0;
    for (pos = 0; pos < N; pos++) if (P[pos] == target) break;

    // up
    if (pos != N-1) {
      flip(pos);
      printf("%d ", pos+1);
    }
    // down
    flip(i);
    printf("%d ", i+1);
  }
  printf("0\n");
}

int main()
{
  int c;
  while ((c = getchar()) != EOF) {
    ungetc(c, stdin);
    N = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
      ungetc(c, stdin);
      scanf("%d", P+N);
      N++;
    }

    solve();
  }
}
