#include <iostream>
#define MAXN 1005
#define INF 100005
using namespace std;

int n;
int a[MAXN];
int dp[MAXN];

void trace()
{
  for (int i = 0; i < n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
}

void input()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    dp[i] = INF;
  }
}

void solve()
{
  for (int i = 0; i < n; i++) {
    *lower_bound(dp, dp+n, a[i]) = a[i];
    trace();
  }

  printf("%ld\n", lower_bound(dp, dp+n, INF) - dp);

}

int main()
{
  input();
  trace();
  solve();
}
