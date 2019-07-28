#include <iostream>
using namespace std;
const int MAXN = 10005;

int C[MAXN]; // [1, 5000]
int Y[MAXN]; // [0, 10000]
int N, S;    // [1, 10000], [1, 100]

void input()
{
  scanf("%d%d\n", &N, &S);

  for (int i = 0; i < N; i++) {
    scanf("%d%d", C+i, Y+i);
  }
}

void solve()
{
  long long cost = 0;
  for (int i = 0; i < N; i++) {
    int min = C[i];
    for (int j = i; j > 0; j--) {
      int c = C[j] + (i-j) * S;
      if (c < min) min = c;
    }
    //printf("%d %d\n", Y[i], min);
    cost += min * Y[i];
  }
  printf("%lld\n", cost);
}

int main()
{
  input();
  solve();
}
