#include <stdio.h>

int main()
{
  int year;
  scanf("%d", &year);
  if ((year % 4 == 0 && year % 400 != 0) || (year % 1000 == 0)) {
    printf("yes\n");
  }
  else {
    printf("no\n");
  }
}
