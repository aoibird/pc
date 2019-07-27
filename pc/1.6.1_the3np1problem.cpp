#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int cycle_3np1(int s)
{
  int cnt = 0;
  while (s != 1) {
    if (s % 2 == 0) s = s / 2;
    else s = s * 3 + 1;
    cnt++;
  }
  return cnt+1;
}

int main()
{
  // for each test case run input
  int i, j; // (0, 1 000 000)
  while (scanf("%d%d", &i, &j) == 2) {
    // for [i, j] get cycle length and save maximum value
    int M = 0;
    for (int t = i; t <= j; t++) {
      int result = cycle_3np1(t);
      M = max(result, M);
    }
    // print the maximum value
    printf("%d %d %d\n", i, j, M);
  }

}
