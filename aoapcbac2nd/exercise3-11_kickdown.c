#include <stdio.h>
#define MAXS 105

int s1[MAXS];
int s2[MAXS];
int n1, n2;

void trace()
{
  for (int i = 0; i < n1; i++) {
    printf("%d ", s1[i]);
  }
  printf("\n");
  for (int i = 0; i < n2; i++) {
    printf("%d ", s2[i]);
  }
  printf("\n\n");
}

void input()
{
  char c;
  n1 = 0, n2 = 0;
  while ((c = getchar()) != '\n') {
    s1[n1++] = (char) c - '0';
  }
  //trace();
  while ((c = getchar()) != '\n') {
    s2[n2++] = (char) c - '0';
  }

  //trace();
}

void solve()
{
  int *p = s1, *q = s2;
  if (n1 > n2) {
    int temp = n1;
    n1 = n2;
    n2 = temp;
    int *t = p;
    p = q;
    q = t;
  }

  int left, right;
  int min = n1 + n2;
  int t = min;
  for (left = -n1; left < n2; left++) {
    //printf("left: %d\n", left);
    right = left + n1;
    int ok = 1;
    for (int x = 0; x < right; x++) {
      //printf("s1[x] s2[x-left] %d %d\n", s1[x], s2[x-left]);
      if (s1[x] + s2[x-left] > 3) {
        ok = 0;
      }
    }
    //printf("ok %d\n", ok);
    if (ok) {
      if (left < 0) {
        t = n2 - left;
      }
      else if (right < n2) {
        t = n2;
      }
      else {
        t = right;
      }
      if (t < min) min = t;
    }

    //printf("min: %d\n", min);
  }
  printf("%d\n", min);

}

int main()
{
  int c;
  while ((c = getchar()) != EOF) {
    ungetc(c, stdin);
    input();
    solve();
  }
}
