#include <iostream>
#include <cstdio>
#define MAXS 130
using namespace std;

char sp[MAXS];
int n;

int main()
{
  int T;
  scanf("%d", &T); getchar();
  for (int i = 0; i < T; i++) {
    n = -1;
    int balance, ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
      if (ch == '[' || ch == '(') sp[++n] = ch;
      else if (n == -1) sp[++n] = ch;
      else if (ch == ']' && sp[n] == '[') n--;
      else if (ch == ')' && sp[n] == '(') n--;
      else ;
    }
    //printf("%d\n", n);
    if (n != -1) balance = 0;
    else balance = 1;

    if (balance) printf("Yes\n");
    else printf("No\n");
  }
}
