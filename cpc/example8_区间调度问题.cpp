#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
  // input
  int n;
  cin >> n;

  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s;
    cin >> t;
    v.push_back(make_pair(t, s));
  }
  int count = 1;

  // solve
  sort(v.begin(), v.end());
  int t = 0;
  for (int i = 1; i < v.size(); i++) {
    if (v[i].second > t) {
      count += 1;
      t = v[i].first;
    }
  }

  // output
  cout << count << endl;
}
