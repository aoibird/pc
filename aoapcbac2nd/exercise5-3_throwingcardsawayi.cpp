// UVa 10935
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;

void solve()
{
  queue<int> qr;
  queue<int> qt;
  for (int i = 0; i < n; i++) {
    qr.push(i+1);
  }

  while (qr.size() > 1) {
    int t = qr.front(); qr.pop();
    int b = qr.front(); qr.pop();
    qt.push(t);
    qr.push(b);
  }

  printf("Discarded cards:");
  bool first = true;
  while (!qt.empty()) {
    if (first) { printf(" "); first = false; }
    else printf(", ");
    printf("%d", qt.front()); qt.pop();
  }
  printf("\n");
  printf("Remaining card: %d\n", qr.front()); qr.pop();
}

int main()
{
  while (scanf("%d", &n) == 1 && n) {
    solve();
  }
}
