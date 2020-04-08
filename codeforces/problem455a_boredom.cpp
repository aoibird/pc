#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#define INVALID -1
using namespace std;

typedef map<int,int> seq;
//const int MAXN = 100000+10;
int N;
map<seq,int> P;
seq NR;
seq FINAL;

void print(seq s)
{
  for (seq::iterator it = s.begin(); it != s.end(); it++) {
    printf("%d->%d ", it->first, it->second);
  }
  printf("\n");
}

int get_points(seq s)
{
  if (P.count(s) > 0) return P[s];

  int value = 0;
  for (seq::iterator it = s.begin(); it != s.end(); it++) {
    int number = it->first;
    // printf("number = %d\n", number);
    bool empty_plus = (s.count(number+1) <= 0) ||
      (s.count(number+1) > 0 && s[number+1] == 0);
    bool empty_minus = (s.count(number-1) <= 0) ||
      (s.count(number-1) > 0 && s[number-1] == 0);

    if (empty_plus && empty_minus && s[number] < NR[number]) {
      s[number] += 1;
      // printf("value = max(value, get_points(s) + number);\n");
      // print(s);
      value = max(value, get_points(s) + number);
      s[number] -= 1;
    }
  }
  P[s] = value;
  return value;
}


int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a; scanf("%d", &a);
    NR[a] += 1;
    FINAL[a] = 0;
  }
  // print(FINAL);
  // print(NR);

  int res = get_points(FINAL);
  printf("%d\n", res);
}
