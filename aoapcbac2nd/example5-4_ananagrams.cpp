#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

map<string, int> cnt;
vector<string> orig;

string unify(string w)
{
  for (int i = 0; i < w.size(); i++) {
    w[i] = tolower(w[i]);
  }

  sort(w.begin(), w.end());

  return w;
}

int main()
{
  string w;
  while (cin >> w) {
    if (w == "#") break;
    orig.push_back(w);

    w = unify(w);
    cnt[w] += 1;
  }
  sort(orig.begin(), orig.end());

  for (auto e : orig) {
    string s = unify(e);
    if (cnt[s] == 1) cout << e << endl;
  }
}
