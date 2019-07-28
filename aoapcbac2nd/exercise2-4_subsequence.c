#include <stdio.h>

double solve(long long n, long long m)
{
  double sum = 0;
  for (long long i = n; i <= m; i++) {
    sum += 1.0 / (i*i);
  }

  return sum;
}

int main()
{
  long long n, m;
  int i = 1;
  while (scanf("%lld%lld", &n, &m) == 2 && n != 0 && m != 0) {
    double result = solve(n, m);
    printf("Case %d: %.5f\n", i, result);

    i++;
  }

}
