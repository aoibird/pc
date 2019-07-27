#include <iostream>
#include <map>
#define MAXN 500005
using namespace std;

int a[MAXN][2];
int N;

void solve()
{
  map<pair<int, int>, int> peer;
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &a[i][0], &a[i][1]);
    int s1, s2;
    if (a[i][0] < a[i][1]) {
      s1 = a[i][0];
      s2 = a[i][1];
    }
    else {
      s2 = a[i][0];
      s1 = a[i][1];
    }
    peer[make_pair(s1, s2)] += 1;
  }

  int ok = 1;
  for (int i = 0; i < N; i++) {
    int s1, s2;
    if (a[i][0] < a[i][1]) {
      s1 = a[i][0];
      s2 = a[i][1];
    }
    else {
      s2 = a[i][0];
      s1 = a[i][1];
    }

    if (peer[make_pair(s1, s2)] % 2 != 0) {
      ok = 0;
      break;
    }
  }

  if (ok) printf("YES\n");
  else printf("NO\n");
}

int main()
{
  while (scanf("%d", &N) == 1 && N) {
    solve();
  }
}

