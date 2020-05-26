// UVa 10340
#include <stdio.h>
#include <string.h>
#define MAXS 1000000

char s[MAXS];
char t[MAXS];

void input()
{
  scanf("%s", t);
  scanf("%s", s);

  //printf("%s\n", s);
  //printf("%s\n", t);
}

int solve()
{
    int ls = strlen(s);
    int lt = strlen(t);
    int p = 0;
    for (int i = 0; i < ls; i++) {
        if (t[p] == s[i]) p++;
    }

    if (p == lt) return 1;
    else return 0;
}

int main()
{
  int c;
  while ((c = getchar()) != EOF) {
    ungetc(c, stdin);
    //printf("%c\n", c);
    input();
    //printf("%s %s\n", s, t);
    int result = solve();

    if (result) printf("Yes\n");
    else printf("No\n");

    getchar();
  }
}
