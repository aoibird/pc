#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define MAXL 1005
#define MAXC 90
#define MAXW 90
using namespace std;

vector<string> lines[MAXL];
int maxsize[MAXW];
int l, w;

void trace()
{
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      cout << lines[i][j] << "|";
    }
    cout << endl;
  }

  for (int i = 0; i < w; i++) {
    cout << maxsize[i] << " ";
  }
  cout << endl;
}

void input()
{
  fill(maxsize, maxsize+3, 0);
  //char buff[MAXC];
  char word[MAXC];
  //int p = 0, t = 0;
  string s;
  string buff;

  while (getline(cin, buff)) {
    int ls = buff.size();
    int p = 0, t = 0;
    int i;
    for (i = 0; p < ls; i++) {
      while (p < ls && buff[p] == ' ') p++;
      while (p < ls && buff[p] != ' ') word[t++] = buff[p++];
      word[t] = '\0';
      s = word;
      if (t != 0) lines[l].push_back(s);
      if (t != 0 && t > maxsize[i]) maxsize[i] = t;
      //printf("t = %d\n", t);
      t = 0;

      //printf("p = %d (%c)\n", p, buff[p]);
    }
    if (i > w) w = i;
    p = 0;
    l++;
  }

  //trace();
}

void format()
{
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      int wl = lines[i][j].size();
      int ml = maxsize[j];
      cout << lines[i][j];
      if (j == lines[i].size() - 1) continue;
      for (int k = 0; k < ml - wl + 1; k++) {
        cout << " ";
      }
    }
    cout << endl;
  }
}

int main()
{
  input();
  format();
}
