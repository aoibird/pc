#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100+10];
int b[100+10];

int main()
{
  int m, s;
  scanf("%d%d", &m, &s);

  if (s < 1 || s > m*9) {
    printf("-1 -1\n");
    return 0;
  }

  int s1 = s;
  for (int i = 0; i < m; i++) {
    if (i == 0) {
      if ((m-1)*9 >= s1) a[i] = 1;
      else a[i] = s1 - (m-1)*9;
    }
    else {
      if ((m-1-i)*9 >= s1) a[i] = 0;
      else a[i] = s1 - (m-i-1) * 9;
    }

    s1 -= a[i];
  }

  int s2 = s;
  for (int i = 0; i < m; i++) {
    b[i] = (s2 > 9) ? 9 : s2;
    s2 -= b[i];
  }



  for (int i = 0; i < m; i++)
    printf("%d", a[i]);
  printf(" ");
  for (int i = 0; i < m; i++)
    printf("%d", b[i]);
  printf("\n");

  return 0;
}
