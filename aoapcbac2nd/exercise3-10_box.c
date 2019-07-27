#include <stdio.h>
#include <string.h>

int a[12] = {0};
int set[12] = {0};
int cnt[12] = {0};
int n = 0;

void trace()
{
  for (int i = 0; i < n; i++) {
    printf("%d ", set[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", cnt[i]);
  }
  printf("\n");
}

int solve()
{
  for (int i = 0; i < 12; i++) {
    int x = a[i];
    int include = 0;
    for (int j = 0; j < n; j++) {
      if (x == set[j]) {
        include = 1;
        cnt[j] += 1;
      }
    }

    if (include == 0) {
      set[n] = x;
      cnt[n] = 1;
      n += 1;
    }

    //trace();
  }


  if (n != 3) {
    return 0;
  }
  else {
    for (int i = 0; i < n; i++) {
      if (cnt[i] != 4) {
        return 0;
      }
    }
    return 1;
  }
}

int main()
{
  while (1) {
    // input
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    memset(set, 0, sizeof(set));
    n = 0;
    for (int i = 0; i < 12; i++) {
      if (scanf("%d", &a[i]) != 1) {
        return 0;
      }
    }

    // solve
    int result = solve();

    if (result) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
  }
}
