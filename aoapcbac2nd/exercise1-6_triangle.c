#include <stdio.h>

int main()
{
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  if (x > y && x > z) {
    if (y + z <= x) printf("not a triangle\n");
    else if (y*y + z*z == x*x) printf("yes\n");
    else printf("no\n");
  }
  else if (y > x && y > z) {
    if (x + z <= y) printf("not a triangle\n");
    else if (x*x + z*z == y*y) printf("yes\n");
    else printf("no\n");
  }
  else if (z > x && z > y) {
    if (x + y <= z) printf("not a triangle\n");
    else if (x*x + y*y == z*z) printf("yes\n");
    else printf("no\n");
  }
  else {
    printf("no\n");
  }
}
