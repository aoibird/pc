#include <iostream>
using namespace std;

int main()
{
  string s;
  string t;
  getline(cin, s);
  getline(cin, t);

  bool ok = false;
  for (int i = 0; i < s.size(); i++) {
    if (t[i] == 'h') {
      ok = true;
    }
  }

  if (ok) {
    cout << "go\n";
  }
  else {
    cout << "no\n";
  }

}
