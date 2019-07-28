#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 4005;
typedef long long ll;

int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int CD[MAXN*MAXN];
int N;

void input()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", A+i);
    scanf("%d", B+i);
    scanf("%d", C+i);
    scanf("%d", D+i);
  }
  // for (int i = 0; i < N; i++) {
  //   scanf("%d", B+i);
  // }
  // for (int i = 0; i < N; i++) {
  //   scanf("%d", C+i);
  // }
  // for (int i = 0; i < N; i++) {
  //   scanf("%d", D+i);
  // }
}

void solve()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      CD[i*N+j] = C[i] + D[j];
    }
  }
  sort(CD, CD+N*N);

  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int cd = -(A[i] + B[j]);
      cnt += upper_bound(CD, CD+N*N, cd) - lower_bound(CD, CD+N*N, cd);
    }
  }
  printf("%lld\n", cnt);
}

int main()
{
  input();
  solve();
}
