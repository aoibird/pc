#include <iostream>
using namespace std;
const int MAXN = 18;

int S[MAXN]; // S[i] [-10, 10]
int N; // [1, 18]

int main()
{
  int T = 1;
  while (scanf("%d", &N) == 1) {
    for (int i = 0; i < N; i++) scanf("%d", S+i);

    long long M = -1000000000000000005;
    for (int i = 0; i < N; i++) {
      long long prod = 1;
      for (int j = i; j < N; j++) {
        prod *= S[j];
        if (prod > M) M = prod;
      }
    }

    printf("Case #%d: The maximum product is ", T);
    if (M < 0) printf("0.\n\n");
    else printf("%lld.\n\n", M);
    T++;
  }
}
