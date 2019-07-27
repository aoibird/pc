#include <iostream>
using namespace std;

int main()
{
  int K;
  while (scanf("%d", &K) == 1) {
    int cnt = 0;
    for (int y = K+1; y <= 2*K; y++) {
      if ((K * y) % (y - K) == 0) cnt++;
    }
    printf("%d\n", cnt);

    for (int y = K+1; y <= 2*K; y++) {
      if ((K * y) % (y - K) == 0)
        printf("1/%d = 1/%d + 1/%d\n", K, (K*y)/(y-K), y);
    }
  }
}
