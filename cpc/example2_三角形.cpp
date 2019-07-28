#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  int ok = false;
  for (int i = n - 1; i - 2 >= 0; i--) {
    if (v[i] < v[i-1] + v[i-2]) {
      ok = true;
      cout << (v[i] + v[i-1] + v[i-2]) << "\n";
      break;
    }
  }

  if (ok == false) {
    cout << "0\n";
  }
}
