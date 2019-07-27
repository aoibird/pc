#include <iostream>
using namespace std;

int main()
{
  string s;
  getline(cin, s);
  int loc = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      if (loc == 0) loc = 1;
      else if (loc == 1) loc = 0;
      else ;
    }
    else if (s[i] == 'B') {
      if (loc == 1) loc = 2;
      else if (loc == 2) loc = 1;
      else ;
    }
    else if (s[i] == 'C') {
      if (loc == 0) loc = 2;
      else if (loc == 2) loc = 0;
      else ;
    }
    else {
      ;
    }
  }

  cout << loc + 1 << endl;
}
