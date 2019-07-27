#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
int k[3] = {2, 3, 5};

int main()
{
  priority_queue<ll, vector<ll>, greater<ll> > pq;
  set<ll> s;
  pq.push(1);
  s.insert(1);
  for (int i = 1; i < 1500; i++) {
    ll x = pq.top(); pq.pop();

    for (int j = 0; j < 3; j++) {
      ll t = x * k[j];
      if (!s.count(t)) {
        pq.push(t);
        s.insert(t);
      }
    }
  }
  ll x = pq.top(); pq.pop();
  cout << "The 1500'th ugly number is " << x <<".\n";
}
