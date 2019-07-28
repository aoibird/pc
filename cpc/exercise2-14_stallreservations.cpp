#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 50050
#define MAXAB 1000100
using namespace std;
typedef pair<int,int> PII;

struct cow {
  int index;
  int start;
  int finish;
  int stall;
};


cow a[MAXN];
int f[MAXN]; // finish
int N;


void input()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &a[i].start, &a[i].finish);
    a[i].index = i;
  }
}

int cmpfinish(cow x, cow y)
{
  if (x.start < y.start) return 1;
  else return 0;
}

int cmpindex(cow x, cow y)
{
  if (x.index < y.index) return 1;
  else return 0;
}

void solve()
{
  sort(a, a+N, cmpfinish);
  priority_queue<PII, vector<PII>, greater<PII> > pq;

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    PII t;
    //if (!pq.empty()) printf("%d %d\n", pq.top().first, pq.top().second);
    //else printf("0 0\n");
    if (!pq.empty() && pq.top().first < a[i].start) { // old
      t = pq.top(); pq.pop();
      pq.push(PII(a[i].finish, t.second)); // update finish time of old stall
      a[i].stall = t.second;
      //printf("old: %d %d %d\n", a[i].start, a[i].finish, a[i].stall);
    }
    else { // new
      cnt++;
      pq.push(PII(a[i].finish, cnt)); // add new stall
      a[i].stall = cnt;
      //printf("new: %d %d %d\n", a[i].start, a[i].finish, a[i].stall);
    }

  }

  printf("%d\n", cnt);
  sort(a, a+N, cmpindex);
  for (int i = 0; i < N; i++) {
    printf("%d\n", a[i].stall);
  }

  /*
  for (int i = 1; i <= cnt; i++) {
    printf("%d ", f[i]);
  }
  printf("\n");
  */
}

int main()
{
  input();
  solve();
}
