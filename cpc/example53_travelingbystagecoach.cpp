// POJ 2686
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct State {
  int city;
  int tickets;
  State(int c=0, int t=0) {
    city = c;
    tickets = t;
  }
};

const int MAXN = 8;
const int MAXM = 30;
const int INF = 100000000;
int N; // the number of coach tickets [1, 8]
int M; // the number of cities in the network [2, 30]
int P; // the number of roads between cities
int A, B; // from city A to B
int T[MAXN+3]; // tickets T[i] ~ [1, 10]
int G[MAXM+3][MAXM+3]; // distance G[i][j] ~ [1, 100]

int S[MAXN+3]; // my tickets
double D[MAXM+3][(1 << MAXN)+3];

void input()
{
  for (int i = 1; i <= M; i++)
    for (int j = 1; j <= M; j++)
      G[i][j] = 0;
  for (int i = 0; i < N; i++) S[i] = 1;
  for (int i = 1; i <= M; i++)
    for (int j = 0; j < (1 << N); j++)
      D[i][j] = INF;

  for (int i = 0; i < N; i++) scanf("%d", T+i);
  for (int i = 0; i < P; i++) {
    int f, t, d;
    scanf("%d%d%d", &f, &t, &d);
    G[f][t] = d;
    G[t][f] = d;
  }
}

double solve()
{
  double res = INF;
  D[A][(1<<N)-1] = 0;

  for (int s = (1 << N) - 1; s >= 0; s--) {
    res = min(res, D[B][s]);
    for (int f = 1; f <= M; f++) {
      for (int i = 0; i < N; i++) {
        if (s >> i & 1) {
          for (int t = 1; t <= M; t++) {
            if (G[f][t] > 0) {
              D[t][s & ~(1 << i)] = min(D[t][s & ~(1 << i)],
                                        D[f][s] + G[f][t] / (double)T[i]);
            }
          }
        }
      }
    }
  }

  return res;
}


int main()
{
  while(scanf("%d%d%d%d%d", &N, &M, &P, &A, &B) == 5) {
    if (N == 0 && M == 0 && P == 0 && A == 0 && B == 0) break;
    input();
    double res = solve();

    if ((int) res == INF) printf("Impossible\n");
    else printf("%.3f\n", res);
  }
}
