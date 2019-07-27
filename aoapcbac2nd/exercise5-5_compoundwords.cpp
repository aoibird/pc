#include <iostream>
#include <algorithm>
#define MAXW 120050
using namespace std;

string words[MAXW];
int W;

void input()
{
  string s;
  while (cin >> s) {
    words[W++] = s;
  }
}

void solve()
{
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < W; j++) {
      string s = words[i] + words[j];
      int p = lower_bound(words, words+W, s) - words;

      if (words[p] == s) cout << s << endl;
    }
  }
}

int main()
{
  input();
  solve();
}
