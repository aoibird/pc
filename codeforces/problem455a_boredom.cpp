#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 100000+10;
map<int,int> DP[MAXN];
int R[MAXN];
int N;
map<int,int> NR;

void print(int i)
{
  printf("%d: ", i);
  for (map<int,int>::iterator it = DP[i].begin();
         it != DP[i].end(); it++) {
    printf("%d->%d ", it->first, it->second);
  }
  printf("(%d)\n", R[i]);
}

int count_rest(int i)
{
  int sum = 0;
  for (map<int,int>::iterator it = DP[i].begin();
         it != DP[i].end(); it++) {
    sum += (it->first * it->second);
  }
  return sum;
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a; scanf("%d", &a);
    NR[a] += 1;
  }

  DP[0] = NR;
  int start = MAXN;
  // print(0);
  for (map<int,int>::iterator it = NR.begin();
         it != NR.end(); it++) {
    int number = it->first;
    DP[number] = NR;
    DP[number].erase(number+1);
    DP[number].erase(number-1);
    DP[number][number] = NR[number] - 1;
    if (DP[number][number] == 0) DP[number].erase(number);
    R[number] = count_rest(number);
    start = min(start, number);
  }
  int i;
  int mx;
  for (i = start, mx = start+1; i <= mx; i++) {
    for (map<int,int>::iterator it = DP[i].begin();
         it != DP[i].end(); it++) {
      int number = it->first;
      if (R[i] - number > R[i+number]) {
        DP[i+number] = DP[i];
        // DP[i+number][number] -= 1;
        if (--DP[i+number][number] == 0) DP[i+number].erase(number);
        R[i+number] = R[i] - number;
        // printf("i:%d number:%d i+number:%d R[i]:%d R[i+number]:%d\n",
        //        i, number, i+number, R[i], R[i+number]);
      }
      // print(i);
      // print(i+number);
      mx = max(mx, i+number);
      // if (DP[i].empty() && i == mx) break;
    }

    // for (int j = 0; j < 10; j++) {
    //   printf("%d%c", R[j], j==9?'\n':' ');
    // }
    // for (int j = 0; j < 10; j++) print(i);
  }
  // print(i);
  printf("%d\n", mx);

}
