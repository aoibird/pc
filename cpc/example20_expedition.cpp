#include <iostream>
#include <queue>
#define MAXN 10005
using namespace std;
typedef pair<int,int> PII;

int n, l, p;
PII T[MAXN];


void input()
{
  cin >> n;
  for (int i = n-1; i >= 0; i--) {
    cin >> T[i].first >> T[i].second;
  }
  cin >> l >> p;
  for (int i = 0; i < n; i++) {
    T[i].first = l - T[i].first;
    //printf("%d %d\n", a[i], b[i]);
  }
}

void solve()
{
  T[n].first = l;
  T[n].second = 0;
  n++;
  sort(T, T+n);

  priority_queue<int> pq;
  int cnt = 0, pos = 0, tank = p;

  for (int i = 0; i < n; i++) {
    int d = T[i].first - pos;

    while (tank - d < 0) {
      if (pq.empty()) {
        cout << "-1";
        return;
      }
      //printf("%d\n", pq.top());
      tank += pq.top(); pq.pop();
      cnt++;
    }

    tank -= d;
    pos = T[i].first;
    pq.push(T[i].second);
  }

  cout << cnt << endl;
}

int main()
{
  input();
  solve();
}
