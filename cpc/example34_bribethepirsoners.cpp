#include <iostream>
#include <queue>
#define MAXP 1005
#define MAXQ 105
using namespace std;

int P, Q;
priority_queue<int> pq;

void input()
{
  cin >> P >> Q;
  while (pq.size() > 0) pq.pop();
  int pre, x, len;
  cin >> pre;
  pq.push(-pre);
  for (int i = 1; i < Q; i++) {
    cin >> x;
    len = x - pre;
    pq.push(-len);
    pre = x;
    //cout << len << endl;
  }
  len = P - pre;
  pq.push(-len);
  //cout << len << endl;
}

int solve()
{

  int sum = 0;
  while (pq.size() > 1) {
    int s1 = -pq.top(); pq.pop();
    int s2 = -pq.top(); pq.pop();
    sum += (s1 + s2);
    pq.push(- (s1+s2));
  }

  return sum - Q;
}


int main()
{
  int rnd;
  cin >> rnd;
  for (int i = 0; i < rnd; i++) {
    input();
    int res = solve();
    cout << "Case #" << i+1 << ": " << res << endl;
  }
}
