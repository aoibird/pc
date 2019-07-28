#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, m;

bool dfs(int i, int sum)
{
  if (i == n) return (sum == m);

  if (dfs(i+1, sum)) return true;

  if (dfs(i+1, sum + v[i])) return true;

  return false;
}

int main()
{
  cin >> n >> m;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  bool ok = dfs(0, 0);

  if (ok) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
}
