// POJ 1068
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int LP = 0;
const int MAXN = 20+10;
int A[MAXN];
int N;
stack<int> S;

void input()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", A+i);
  }
}

void solve()
{
  for (int i = N-1; i >= 1; i--) A[i] = A[i] - A[i-1];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < A[i]; j++) S.push(LP);
    int sum = 0;
    while (S.top() > 0) { sum += S.top(); S.pop(); }
    sum += 1;
    S.pop();
    S.push(sum);
    A[i] = sum;
    //printf("%d\n", sum);
  }
}

void output()
{
  for (int i = 0; i < N; i++) {
    printf("%d", A[i]);
    if (i < N-1) printf(" ");
    else printf("\n");
  }
}

int main()
{
  int T; scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    input();
    solve();
    output();
  }
}
