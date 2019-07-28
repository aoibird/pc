#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;


int main()
{
  int n;
  cin >> n;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pq.push(-x);
  }

  if (n == 1) {
    cout << -pq.top() << endl;
    return 0;
  }

  ll cost = 0;
  while (pq.size() > 1) {
    int s1 = -pq.top(); pq.pop();
    int s2 = -pq.top(); pq.pop();

    int c = s1 + s2;
    cost += c;
    pq.push(-c);
  }

  cout << cost << endl;
}
