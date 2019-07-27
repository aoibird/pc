#include <iostream>
using namespace std;

int main()
{
  int c, r;
  cin >> r >> c;
  printf("%.6f\n", ((r - c) * (r - c)) / (r * r * 1.0) * 100);

}
