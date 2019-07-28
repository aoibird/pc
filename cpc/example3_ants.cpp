#include <iostream>
using namespace std;

int main()
{
  int line;
  cin >> line;
  for (int i = 0; i < line; i++) {
    int l;
    int n;
    cin >> l >> n;
    int x;
    int mi = 0;
    int ma = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      ma = max(ma, max(x, l - x));
      mi = max(mi, min(x, l - x));
    }

    cout << mi << " " << ma << "\n";
  }
}
