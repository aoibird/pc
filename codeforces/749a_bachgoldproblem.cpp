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
  int n;
  while (scanf("%d", &n) == 1) {
    int k = n/2;
    printf("%d\n", k);
    for (int i = 0; i < k-1; i++) printf("2 ");
    (n % 2 == 0) ? printf("2\n") : printf("3\n");
  }
}
