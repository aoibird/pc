#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int K, A, B;

int solve(int level, int r, int c)
{
  if (level == 0) {
    //printf("%d %d %d\n", level, r, c);
    if (r >= A && r <= B) return 1;
    else return 0;
  }
  int ns = 1 << (level-1);
  int x = solve(level-1, r, c);
  int y = solve(level-1, r+ns, c);
  int z = solve(level-1, r, c+ns);
  return (x + y + z);
}

int main()
{
  int T; scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d%d%d", &K, &A, &B);
    int res = solve(K, 1, 1);
    printf("Case %d: %d\n", i+1, res);
  }
}
