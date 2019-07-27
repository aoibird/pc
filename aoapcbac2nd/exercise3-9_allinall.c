#include <stdio.h>
#define MAXS 1000

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
  int i = 0, j = 0;
  while (s[i] != '\0' && t[j] != '\0') {
    //printf("%c %c\n", s[i], t[j]);
    if (s[i] == t[j]) j++;

    i++;
  }

  return (t[j] == '\0');
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
