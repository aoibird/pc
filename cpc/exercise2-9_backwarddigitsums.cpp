#include <iostream>
#include <algorithm>
#define MAXN 15
using namespace std;

int a[MAXN];
int n;
int s;

void input()
{
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; i++) {
    a[i] = i+1;
  }
}

void trace()
{
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void solve()
{
  int temp[MAXN];

  do {
    //trace();
    for (int i = 0; i < n; i++) {
      temp[i] = a[i];
    }

    for (int i = n; i > 1; i--) {
      for (int j = 0; j < i-1; j++) {
        temp[j] = temp[j] + temp[j+1];
      }
    }
    //printf("%d\n", temp[0]);

    if (temp[0] == s) {
      printf("%d", a[0]);
      for (int i = 1; i < n; i++) {
        printf(" %d", a[i]);
      }
      printf("\n");
      break;
    }
  } while(next_permutation(a, a+n));


}

int main()
{
  input();
  solve();
}
