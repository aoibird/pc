#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;
vector<string> v;
const int MAXL = 8000000+10;

int main()
{
  int n; scanf("%d", &n);
  string s;
  char str[MAXL];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    s = string(str);
    m[s] += 1;
    if (m[s] > 1) { v.push_back(s); cnt++; }
  }

  if (cnt == 0) printf("SAFO\n");
  else {
      printf("%d\n", cnt);
      for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
  }
}
