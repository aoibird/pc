#include <stdio.h>

int main()
{
  int c;
  int left = 1;
  while ((c = getchar()) != EOF) {
    if (c == '"') {
      printf("%s", (left ? "``" : "''"));
      left = !left;
    }
    else {
      printf("%c", c);
    }
  }
}
