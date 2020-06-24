// UVa 10391
#include <iostream>
#include <algorithm>
#include <set>
#define MAXW 120050
#define MAXL 10000
using namespace std;

string words[MAXW];
int W;
char S[MAXL];
set<string> w;

void input()
{
  W = 0;
  while (scanf("%s", S) == 1) {
    words[W++] = S;
  }
}

void solve()
{
    for (int i = 0; i < W; i++) {
        int l = words[i].size();
        for (int j = 1; j < l; j++) {
            string s = words[i].substr(0, j);
            string t = words[i].substr(j, l-j);
            // printf("%s %s\n", s.c_str(), t.c_str());
            int p = lower_bound(words, words+W, s) - words;
            int q = lower_bound(words, words+W, t) - words;
            if (p >= 0 && p < W && words[p] == s
                && q >= 0 && q < W && words[q] == t) {
                w.insert(words[i]);
            }
        }
    }
    for (set<string>::iterator it = w.begin();
         it != w.end(); it++) {
        printf("%s\n", (*it).c_str());
    }
}

int main()
{
  input();
  solve();
}
