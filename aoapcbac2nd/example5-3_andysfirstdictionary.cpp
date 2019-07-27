#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <set>
using namespace std;

set<string> dict;

int main()
{
  string s, buff;
  while (cin >> s) {
    for (int i = 0; i < s.size(); i++) {
      if (isalpha(s[i])) s[i] = tolower(s[i]);
      else s[i] = ' ';
    }
    stringstream ss(s);
    while (ss >> buff) dict.insert(buff);
  }

  for (auto e : dict) {
    cout << e << endl;
  }
  // for (set<string>:: iterator it = dict.begin(); it != dict.end(); it++) {
  //   cout << *it << endl;
  // }
}
