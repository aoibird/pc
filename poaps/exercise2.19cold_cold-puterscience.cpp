#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int cnt = 0;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x < 0) {
      cnt += 1;
    }
  }

  cout << cnt << endl;
}
