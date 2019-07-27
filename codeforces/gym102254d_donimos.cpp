#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int x;
  vector<int> v;
  for (int i = 0; i < 2 * n; i++) {
    cin >> x;
    v.push_back(x);
  }

  /*
  int min = 2000000000, max = 0;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      int s = a[i] + a[j];
      if (s < min) min = s;
      if (s > max) max = s;
      printf("%d + %d = %d\n", a[i], a[j], s);
    }
  }

  cout << max - min << "\n";
  */

  sort(v.begin(), v.end());
  // for (int i = 0; i < v.size(); i++) {
  //   printf("%d\n", v[i]);
  // }
  int i, j;
  int max = 0, min = 2000000000;
  for (i = 0, j = 2 * n - 1; i < j; i++, j--) {
    int s = v[i] + v[j];
    // printf("%d + %d = %d\n", v[i], v[j], s);
    if (s > max) max = s;
    if (s < min) min = s;
  }

  cout << max - min << "\n";
}
