#include <iostream>
#include <vector>
#include <list>
#define MAXN 105
using namespace std;

vector<int> G[MAXN];
int color[MAXN];
int N, M;
list<int> topo;

void init()
{
  for (int i = 0; i < N; i++) {
    G[i].resize(0);
    color[i] = 0;
  }
  topo.resize(0);
}

void input()
{
  for (int i = 0; i < M; i++) {
    int from, to;
    scanf("%d%d", &from, &to);
    G[from-1].push_back(to-1);
  }
}

void dfs(int s)
{
  color[s] = 1;
  for (int i = 0; i < G[s].size(); i++) {
    int to = G[s][i];
    if (color[to] == 0) dfs(to);
  }
  topo.push_front(s);
}

int main()
{
  while (scanf("%d%d", &N, &M) == 2 && N && M) {
    init();
    input();

    for (int i = 0; i < N; i++) {
      if (color[i] == 0) dfs(i);
    }

    int first = 1;
    for (list<int>::iterator it = topo.begin(); it != topo.end(); it++) {
      if (first) first = 0;
      else printf(" ");
      printf("%d", *it+1);
    }
    printf("\n");
  }
}
