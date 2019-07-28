#include <iostream>
#include <algorithm>
#define MAXN 1005
using namespace std;

int a[MAXN];

void solve(int n, int r)
{
  //int n;
  //cin >> n;

  //int r;
  //cin >> r;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a+n);

  // for (int i = 0; i < n; i++) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;

  int i = 0, count = 0;
  while (i < n) {
    int s = a[i++];
    while (i < n && a[i] <= s + r) i++;

    int p = a[i - 1];
    while (i < n && a[i] <= p + r) i++;

    count++;
  }

  cout << count << "\n";
}

int main()
{
  int n, r;
  while (cin >> r >> n) {
    //printf("%d %d\n", n, r);
    if (n == -1 && r == -1) break;
    solve(n, r);
  }
}
