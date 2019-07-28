#include <iostream>
#define MAXN 1005
#define MAXK 10005
using namespace std;

int n;
int a[MAXN];
int m[MAXN];
int k;
int dp[MAXK];

void trace()
{
  for (int i = 0; i < k; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
}

void input()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> m[i];
  }
}

void solve()
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (dp[j] >= 0) {
        dp[j] = m[i];
      }
      else if (j < a[i] || dp[j - a[i]] <= 0) {
        dp[j] = -1;
      }
      else {
        dp[j] = dp[j - a[i]] - 1;
      }

      trace();
    }
  }

  if (dp[k] >= 0) printf("Yes\n");
  else printf("No\n");
}


int main()
{
  input();
  trace();
  solve();

}
