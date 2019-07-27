#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define MAXN 100100

using namespace std;

//vector<int> G[MAXN];
int degree[MAXN];
string words[MAXN];
int N, T;

void input()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    cin >> words[i];
  }
}

void solve()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      char from = words[i][words[i].size()-1];
      char to = words[j][0];
      if (from == to) {
        //G[i].push_back(j);
        degree[i] += 1;
        degree[j] += 1;
      }
    }
  }

  int odd = 0, even = 0;
  for (int i = 0; i < N; i++) {
    //printf("%d\n", degree[i]);
    if (degree[i] % 2 != 0) odd++;
    if (degree[i] % 2 == 0 && degree[i] != 0) even++;
  }

  if (even == N || odd == 2) printf("Ordering is possible.\n");
  else printf("The door cannot be opened.\n");
}

int main()
{
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    memset(degree, 0, sizeof(degree));
    // for (int i = 0; i < N; i++) {
    //   G[i].resize(0);
    // }
    input();
    solve();
  }
}
