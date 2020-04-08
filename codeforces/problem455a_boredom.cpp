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
typedef map<int,int> seq;
const int MAXN = 100000+10;
ll DP[MAXN];
int N;
seq NR;

void print(seq s)
{
  for (seq::iterator it = s.begin(); it != s.end(); it++) {
    printf("%d->%d ", it->first, it->second);
  }
  printf("\n");
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a; scanf("%d", &a);
    NR[a] += 1;
  }
  for (seq::iterator it = NR.begin(); it != NR.end(); it++) {
    it->second *= it->first;
  }
  // print(NR);

  seq::iterator f = NR.begin();
  DP[f->first] = f->second;
  seq::iterator s = NR.begin(); s++;
  DP[s->first] = (f->second > s->second) ? f->second : s->second;
  seq::iterator it = NR.begin();
  it++; it++;
  for ( ; it != NR.end(); it++) {
    int num = it->first;
    int value = it->second;
    DP[num] = max(DP[num-2]+value, DP[num-1]);
  }

  it = NR.end(); it--;
  printf("%lld\n", DP[it->first]);
}
