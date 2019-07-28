#include <iostream>
#define MAXM 1005
#define MAXN 1005
using namespace std;

int n, m, M;
int dp[MAXM][MAXN];

void trace()
{
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void input()
{
  cin >> n >> m >> M;
}

void solve()
{
  dp[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j - i >= 0) {
        dp[i][j] = (dp[i][j-i] + dp[i-1][j]) % M;
      }
      else {
        dp[i][j] = dp[i-1][j];
      }

      trace();
    }
  }
  cout << dp[m][n] << endl;
}

int main()
{
  input();
  trace();
  solve();
}
