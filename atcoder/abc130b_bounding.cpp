#include <iostream>
#define MAXN 110
using namespace std;

int a[MAXN];
int N, X;

int main()
{
  scanf("%d%d", &N, &X);
  for (int i = 0; i < N; i++) {
    scanf("%d", a+i);
  }
  int d = 0;
  int cnt = 1;
  for (int i = 0; i < N; i++) {
    d = a[i] + d;
    if (d <= X) cnt++;
    else break;
  }
  printf("%d\n", cnt);
}
