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

int encode(int s[], int n)
{
  int code = 0;
  for (int i = 0; i < n; i++) {
    code = code | (s[i] << i);
  }
  return code;
}

void decode(int s[], int n, int code)
{
  for (int i = 0; i < n; i++) {
    s[i] = code & 1;
    code = code >> 1;
  }
}

double bfs()
{
  double res = INF;
  queue<State> q;
  q.push(State(A, encode(S, N)));
  D[A][encode(S, N)] = 0;

  while (!q.empty()) {
    State s = q.front(); q.pop();
    int city = s.city;
    int tickets = s.tickets;
    decode(S, N, tickets);

    // next state
    //printf("(%d,%d) %.3f\n", city, tickets, D[city][tickets]);
    for (int c = 1; c <= M; c++) { // cities
      for (int t = 0; t < N; t++) { // tickets
        if (G[city][c] == 0) {  continue; }
        if (S[t] == 0) {  continue; }
        S[t] = 0;
        double cost = G[city][c] / (double)T[t];
        int nt = encode(S, N);
        S[t] = 1;

        if (D[c][nt] < D[city][tickets] + cost) { continue; }

        q.push(State(c, nt));
        D[c][nt] = D[city][tickets] + cost;
        //printf("    %f (%d,%d) %f\n", cost, c, nt, D[c][nt]);

        if (c == B) res = min(res, D[c][nt]);
      }
    }
  }

  return res;

  // for (int i = 1; i <= M; i++) printf("%f ", D[i]);
  // printf("\n");
}


int main()
{
  while(scanf("%d%d%d%d%d", &N, &M, &P, &A, &B) == 5) {
    if (N == 0 && M == 0 && P == 0 && A == 0 && B == 0) break;
    input();
    double res = bfs();

    if ((int) res == INF) printf("Impossible\n");
    else printf("%.3f\n", res);
  }
}
