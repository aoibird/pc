#include <iostream>
#include <queue>
#define MAXN 10005
using namespace std;

int n, l, p;
int a[MAXN];
int b[MAXN];

void input()
{
  cin >> n;
  for (int i = n-1; i >= 0; i--) {
    cin >> a[i] >> b[i];
  }
  cin >> l >> p;
  for (int i = 0; i < n; i++) {
    a[i] = l - a[i];
    //printf("%d %d\n", a[i], b[i]);
  }
}

void solve()
{
  a[n] = l;
  b[n] = 0;
  n++;

  priority_queue<int> pq;
  int cnt = 0, pos = 0, tank = p;

  for (int i = 0; i < n; i++) {
    int d = a[i] - pos;

    while (tank - d < 0) {
      if (pq.empty()) {
        cout << "-1\n";
        return;
      }
      //printf("%d\n", pq.top());
      tank += pq.top(); pq.pop();
      cnt++;
    }

    tank -= d;
    pos = a[i];
    pq.push(b[i]);
  }

  cout << cnt << endl;
}

int main()
{
  input();
  solve();
}
