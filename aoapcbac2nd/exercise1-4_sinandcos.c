#include <stdio.h>
#include <math.h>

int main()
{
  int n;
  scanf("%d", &n);
  double PI = 3.1415926;
  //printf("%f\n", acos(-1));
  printf("%f\n", sin((n / 180.0) * PI));
  printf("%f\n", cos((n / 180.0) * PI));
}
