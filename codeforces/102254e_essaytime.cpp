#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

const int MAXL = 8000000+10;

unordered_map<string,int> m;
// vector<int> v;
string words[MAXL];
int v[MAXL];
char cha[MAXL];

int main()
{
  int n; scanf("%d", &n); getchar();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
      scanf("%s", cha);
      words[i] = string(cha);
      if (words[i].size() < 4) continue;
      m[words[i]] += 1;
      if (m[words[i]] > 1) { v[cnt++] = i; }
  }

  if (cnt == 0) printf("SAFO\n");
  else {
      printf("%d\n", cnt);
      for (int i = 0; i < cnt; i++) {
          printf("%s\n", words[v[i]].c_str());
      }
  }
}
