#include <iostream>
#include <queue>
#define MAXN 105
using namespace std;

typedef pair<int, int> P;
int N, M;

void solve()
{
  queue<P> q;
  priority_queue<P> pq;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    int prior;
    scanf("%d", &prior);
    q.push(P(prior, i));
    pq.push(P(prior, i));
  }

  int time = 0;
  while (1) {
    P e = q.front(); q.pop();
    P h = pq.top();

    if (e.first == h.first) {
      pq.pop();
      time++;
      if (e.second == M) {
        printf("%d\n", time);
        break;
      }
    }
    else {
      q.push(e);
    }
  }
}

int main()
{
  int rnd;
  scanf("%d", &rnd);
  for (int i = 0; i < rnd; i++) {
    solve();
  }
}
