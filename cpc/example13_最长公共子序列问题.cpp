#include <iostream>
#define MAXS 1000
using namespace std;

string s1, s2;
int dp[MAXS][MAXS];
int R, C;

void trace()
{
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void input()
{
  cin >> s1;
  cin >> s2;
  R = s1.size();
  C = s2.size();
}

void solve()
{
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      cout << s1[i-1] << " " << s2[j-1] << "\n";
      if (s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
      trace();
    }
  }
}


int main()
{
  input();
  trace();
  solve();
}
