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
map<int,int> NR;


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
  for (map<int,int>::iterator it = NR.begin(); it != NR.end(); it++) {
    int num = it->first;
    int value = it->second;
    if (num >= 2) {
      DP[num] = max(DP[num-1], DP[num-2] + value * num);
      M = num;
    }
  }

  printf("%lld\n", DP[M]);
}
