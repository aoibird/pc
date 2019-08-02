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

const int N = 3; // number of cups
const int INF = 500000;
const int MAXV = 200;
int C[N]; // capacity [1, 200)
int V[N]; // volume [1, 200)

int D; // target
int A; // amount of water
int DC; // closeest to target

int visited[MAXV+2][MAXV+2][MAXV+2];

struct Node {
  int v[N];
  int a;
};

int pour(int i, int j)
{
  int from = V[i];
  int to = C[j] - V[j];
  int da = (from > to) ? to : from;
  V[i] -= da;
  V[j] += da;

  return da;
}

void update(int a)
{
  for (int i = 0; i < N; i++) {
    if (V[i] > DC && V[i] <= D) { // closer
      DC = V[i];
      A = a;
    }
    else if (V[i] == DC) { // equal
      if (a < A) A = a;

    }
    else ; // futher
  }
}

void input()
{
  for (int i = 0; i < N; i++) scanf("%d", C+i);
  for (int i = 0; i < N; i++) V[i] = 0;
  V[N-1] = C[N-1];

  scanf("%d", &D);
  A = INF;
  DC = 0;
  memset(visited, 0, sizeof(visited));

  // debug
  // for (int i = 0; i < N; i++) printf("%d ", V[i]);
  // printf("%d\n", D);
  // for (int i = 0; i < N; i++) printf("%d ", C[i]);
  // printf("%d\n", D);
}

void dfs(int a)
{
  update(a);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j || V[i] == 0 || V[j] == C[j]) continue; // skip invalid
      int backup[N];
      for (int k = 0; k < N; k++) backup[k] = V[k]; // backup
      int da = pour(i, j);
      if (visited[V[0]][V[1]][V[2]] == 0) { // visit it
        visited[V[0]][V[1]][V[2]] += 1;
        dfs(a + da);
      }
      else ; // skip visited
      for (int k = 0; k < N; k++) V[k] = backup[k]; // put back
    }
  }

}

class compare
{
public:
  bool operator() (const Node& x, const Node& y) {
    if (x.a > y.a) return true;
    else return false;
  }
};

void bfs()
{
  priority_queue<Node, vector<Node>, compare> q;
  Node s;
  for (int i = 0; i < N; i++) s.v[i] = V[i];
  s.a = 0;
  q.push(s);

  while (!q.empty()) {
    Node curr = q.top(); q.pop();
    for (int k = 0; k < N; k++) V[k] = curr.v[k];

    update(curr.a);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j || V[i] == 0 || V[j] == C[j]) continue;

        int da = pour(i, j); // pour cup i to cup j

        if (visited[V[0]][V[1]][V[2]] == 0) {
          Node next;
          for (int k = 0; k < N; k++) next.v[k] = V[k];
          next.a = curr.a + da;
          q.push(next);
          visited[V[0]][V[1]][V[2]] += 1;
        }

        for (int k = 0; k < N; k++) V[k] = curr.v[k]; // put back
      }
    }
  }
}

void output()
{
  printf("%d %d\n", A, DC);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    input();
    //dfs(0);
    bfs();
    output();
  }
}

