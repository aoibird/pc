#include <iostream>

using namespace std;

int main()
{
  int articles, impact;
  cin >> articles >> impact;
  cout << articles * impact - (articles - 1) << endl;
}
