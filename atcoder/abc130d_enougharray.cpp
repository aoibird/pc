#include <iostream>
#include <cstring>
#define MAXN 10010
using namespace std;

typedef long long ll;
int a[MAXN];
int N;
ll K;
ll mem[MAXN][MAXN];

int main()
{
  scanf("%d%lld", &N, &K);
  //memset(mem, 0, sizeof(mem));
  for (int i = 0; i < N; i++) {
    scanf("%d", a+i);
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (j == i) mem[i][j] = a[j];
      else mem[i][j] = a[j] + mem[i][j-1];

      if (mem[i][j] >= K) cnt++;
    }
  }

  /*
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", mem[i][j]);
    }
    printf("\n");
  }
  */


  printf("%d\n", cnt);

  /*
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int j = i+1;
    if (a[i] > K) {
      cnt += N-i;
    }
    else {
      int sum = a[i];
      while (j < N && sum + a[j] < K) {
        sum += a[j];
        j++;
      }
      cnt += N-j;
    }
  }
  printf("%d\n", cnt);
  */
}
