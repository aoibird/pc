#include <iostream>
#define MAXM 1000
#define MAXN 100
using namespace std;

int dp[MAXM];
int w[MAXN];
int v[MAXN];
int n;
int m;

void input()
{
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
}

void trace()
{
  for (int i = 0; i <= m; i++) {
    cout << dp[i] << " ";
  }
  cout << "\n";
}

int main()
{
  input();
  trace();
  for (int i = 0; i < n; i++) {
    for (int j = w[i]; j <= m; j++) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      trace();
    }
  }

}
