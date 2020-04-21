#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  int d = 0;
  int sum = 1;
  for (int i = 1; i <= N; i++) {
    sum += d;
    d += 4;
  }
  printf("%d\n", sum);
}
