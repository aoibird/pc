#include <iostream>
using namespace std;

int main()
{
  int W, H, x, y;
  scanf("%d%d%d%d", &W, &H, &x, &y);
  if (x * 2 == W && y * 2 == H) {
    printf("%.6f 1\n", (W*H)/2.0);
  }
  else {
    printf("%.6f 0\n", (W*H)/2.0);
  }
}
