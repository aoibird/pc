#include <iostream>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  int reminder, c, d;
  c = a;
  d = b;
  do {
    reminder = c % d;
    c = d;
    d = reminder;
  } while (reminder != 0);

  int lcd = (a * b) / c;

  cout << lcd << "\n";
}
