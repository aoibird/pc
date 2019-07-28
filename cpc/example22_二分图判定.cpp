#include <iostream>
#include <vector>
#define MAXV 1000
using namespace std;

int V;
int color[MAXV] = {0};
vector<int> g[MAXV];

bool dfs(int s, int c)
{
  color[s] = c;
  for (int i = 0; i < g[s].size(); i++) {
    if (color[g[s][i]] == c) return false;
    if (color[g[s][i]] == 0 && !dfs(g[s][i], -c)) return false;
  }

  return true;
}

bool solve()
{
  for (int i = 0; i < V; i++) {
    if (color[i] == 0) {
      if (!dfs(i, 1)) {
        return false;
      }
    }
  }

  return true;
}

int main()
{
  // input
  cin >> V;
  int E;
  cin >> E;
  for (int i = 0; i < E; i++) {
    int from, to;
    cin >> from >> to;
    g[from].push_back(to);
    g[to].push_back(from);
  }

  // solve
  int result = solve();

  if (result) cout << "Yes\n";
  else cout << "No\n";
}
