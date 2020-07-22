#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
#define MAXN 50050
#define MAXAB 1000100

struct cow {
  int index;
  int start;
  int finish;
  int stall;
};


cow A[MAXN];
int N;

bool compare_start(struct cow &a, struct cow &b)
{
    return a.start < b.start;
}

bool compare_index(struct cow &a, struct cow &b)
{
    return a.index < b.index;
}

void solve()
{
  sort(A, A+N, compare_start);
  priority_queue<PII, vector<PII>, greater<PII>> pq; // (finish, index)

  for (int i = 0; i < N; i++) {
      int start = A[i].start, finish = A[i].finish;
      if (pq.empty() || pq.top().first >= start) {
          int size = pq.size();
          pq.push(PII(finish, size)); A[i].stall = size;
      }
      else {
          PII p = pq.top(); pq.pop();
          A[i].stall = p.second;
          pq.push(PII(A[i].finish, p.second));
      }
  }


  printf("%d\n", (int)pq.size());
  sort(A, A+N, compare_index);
  for (int i = 0; i < N; i++) {
    printf("%d\n", A[i].stall+1);
  }
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &A[i].start, &A[i].finish);
            A[i].index = i;
        }
        solve();
    }

}
