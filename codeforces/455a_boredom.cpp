#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 100000+10;
ll DP[MAXN];
int N;
vector<int> NR(MAXN, 0);

int main()
{
  scanf("%d", &N);
  int M = 0;
  for (int i = 0; i < N; i++) {
    int a; scanf("%d", &a);
    NR[a]++;
    M = max(M, a);
  }

  DP[0] = 0;
  DP[1] = NR[1];
  for (ll i = 2; i <= M; i++) {
    DP[i] = max(DP[i-1], DP[i-2] + NR[i] * i);
  }

  printf("%lld\n", DP[M]);
}
