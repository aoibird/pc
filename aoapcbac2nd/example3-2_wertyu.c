#include <stdio.h>
#include <ctype.h>

int main()
{
  char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

  int c;
  while ((c = getchar()) != EOF) {
    int i = 0;
    for (i = 0; s[i] != '\0' && s[i] != c; i++) ;

    if (s[i] == c)
      printf("%c", s[i-1]);
    else
      printf("%c", c);
  }
}
