#include <iostream>
#include <map>
using namespace std;

map<string, int> m;

int main()
{
  int n;
  cin >> n;
  string s;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    // cout << s << endl;
    m[s] += 1;
  }

  int cnt = 0;
  for (auto x : m) {
    cnt += x.second - 1;
  }

  if (cnt == 0) {
    cout << "SAFO\n";
  }
  else {
    cout << cnt << "\n";
    for (auto x : m) {
      for (int i = 1; i < x.second; i++) {
        cout << x.first << "\n";
      }
    }
  }
}
