// POJ 2719
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int off(char ch)
{
  if (ch > '4') ch = ch-'0'-1;
  else ch -= '0';
  return ch;
}

int main()
{
  while (true) {
    char ch = getchar();
    if (ch == '0') break;
    printf("%c", ch);
    ch = off(ch);
    long long d = ch;
    while ((ch = getchar()) != '\n') {
      printf("%c", ch);
      ch = off(ch);
      d = d*9 + ch;
    }
    printf(": %lld\n", d);
  }
}
