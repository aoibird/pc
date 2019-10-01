// POJ 1007
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct DNA {
  string s;
  int cnt;
  DNA(string si="", int c=0) {
    s = si;
    cnt = c;
  }
};
const int MAXM = 50+5;
const int MAXN = 100+5;
DNA S[MAXM];
int M, N;

int cnt(string& s)
{
  int c = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = i+1; j < s.size(); j++) {
      if (s[i] > s[j]) c += 1;
    }
  }
  return c;
}

bool compare(DNA& a, DNA& b)
{
  return a.cnt < b.cnt;
}

int main()
{
  scanf("%d%d", &N, &M); getchar();
  for (int i = 0; i < M; i++) {
    char str[MAXN];
    for (int j = 0; j < N; j++) {
      char c = getchar();
      str[j] = c;
    }
    getchar();
    str[N] = '\0';
    string s = str;
    //cout << s << endl;
    int c = cnt(s);
    S[i] = DNA(s, c);
  }
  sort(S, S+M, compare);

  for (int i = 0; i < M; i++) {
    cout << S[i].s << endl;
  }
}
