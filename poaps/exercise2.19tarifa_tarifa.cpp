#include <iostream>

using namespace std;

int main()
{
  int x, n;
  cin >> x >> n;
  int y;
  int rest = x;
  for (int i = 0; i < n; i++) {
    cin >> y;
    if (rest + x > y) rest = rest + x - y;
    else rest = 0;
  }

  cout << rest << endl;
}
