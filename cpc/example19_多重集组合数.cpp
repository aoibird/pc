#include <iostream>
#define MAXN 1005
#define MAXM 1005
using namespace std;

int n, m, M;
int a[MAXN];
int dp[MAXN][MAXM];

void trace()
{
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void input()
{
  cin >> n >> m >> M;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}

void solve()
{
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  trace();

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j-1-a[i] >= 0) {
        dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]]) % M;
      }
      else {
        dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % M;
      }

      trace();
    }
  }

  cout << dp[n][m] << endl;
}

int main()
{
  input();
  trace();
  solve();
}
