#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;
vector<string> v;

int main()
{
  int n;
  cin >> n;
  string s;
  cin.ignore();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    // cout << s << endl;
    getline(cin, s);
    m[s] += 1;
    if (m[s] > 1) { v.push_back(s); cnt++; }
  }

  if (cnt == 0) printf("SAFO\n");
  else {
      printf("%d\n", cnt);
      for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
  }
}
