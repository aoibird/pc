// POJ 3268
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> PII;
const int INF = 200000000;
const int MAXN = 1000+10;
//const int MAXM = 100000+10;
//Edge ES[MAXM];
int D[MAXN][MAXN];
int G[MAXN][MAXN];
int N; // [1, 1000]
int M; // [1, 100000]
int X;

void print()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) printf("%d ", G[i][j]);
    printf("\n");
  }
}

void dijkstra(int s)
{
  D[s][s] = 0;
  priority_queue<PII> pq;
  pq.push(PII(D[s][s], s));
  while (!pq.empty()) {
    PII curr = pq.top(); pq.pop();
    int v = curr.second;
    int d = curr.first;
    if (D[s][v] < d) continue;
    for (int to = 0; to < N; to++) {
      if (D[s][to] > D[s][v] + G[v][to]) {
        D[s][to] = D[s][v] + G[v][to];
        pq.push(PII(D[s][to], to));
      }
    }
  }
}

void output()
{
  int m = 0;
  for (int i = 0; i < N; i++) {
    m = max(m, D[i][X] + D[X][i]);
  }
  printf("%d\n", m);
}

void init()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) G[i][j] = 0;
      else G[i][j] = INF;
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      D[i][j] = INF;
}

void input()
{
  for (int i = 0; i < M; i++) {
    int from, to, cost;
    scanf("%d%d%d", &from, &to, &cost);
    G[from-1][to-1] = cost;
    //scanf("%d%d%d",&ES[i].from, &ES[i].to, &ES[i].cost);
  }
}

int main()
{
  scanf("%d%d%d", &N, &M, &X); X -= 1;
  init();
  input();
  for (int i = 0; i < N; i++) dijkstra(i);
  //print();
  output();
}
