#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define MAX 10000
using namespace std;



int main()
{
  char s[MAXLEN];
  int stack[MAX];
  int sp = -1;
  int x, y;
  while (cin >> s) {
    switch (s[0]) {
    case '+':
      y = stack[sp--];
      x = stack[sp--];
      stack[++sp] = x + y;
      break;
    case '-':
      y = stack[sp--];
      x = stack[sp--];
      stack[++sp] = x - y;
      break;
    case '*':
      y = stack[sp--];
      x = stack[sp--];
      stack[++sp] = x * y;
      break;
    case '/':
      y = stack[sp--];
      x = stack[sp--];
      stack[++sp] = x / y;
      break;
    default:
      stack[++sp] = atoi(s);
    }
  }

  cout << stack[sp] << endl;
}
