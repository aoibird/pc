#include <stdio.h>
#include <string.h>
#define MAXN 15

int a[MAXN];
int b[MAXN];
int c[MAXN];
int awaken[MAXN];
int period[MAXN];
int n;


void input()
{
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    //printf("%d %d %d\n", a[i], b[i], c[i]);
  }
  memset(awaken, 0, sizeof(awaken));
  memset(period, 0, sizeof(period));
}

void solve()
{
  // initial condition
  for (int i = 0; i < n; i++) {
    if (c[i] <= a[i]) {
      period[i] = a[i] - c[i];
      awaken[i] = 1;
    }
    else {
      period[i] = (a[i] + b[i]) - c[i];
      awaken[i] = 0;
    }
  }


  // simulate
  int cnt = 1;
  while (1) {
    int nawaken = 0;
    for (int i = 0; i < n; i++) {
      if (awaken[i]) nawaken += 1;
    }

    // if all students is awaken
    if (nawaken == n) break;

    for (int i = 0; i < n; i++) {
      if (awaken[i] && period[i] == 0) {
        if (nawaken > n - nawaken) {
          period[i] = a[i];
          awaken[i] = 1;
        }
        else {
          period[i] = b[i];
          awaken[i] = 0;
        }
      }
      else if (!awaken[i] && period[i] == 0) {
        period[i] = a[i];
        awaken[i] = 1;
      }
      else {
        ;
      }
    }

    for (int i = 0; i < n; i++) {
      period[i] -= 1;
    }

    cnt++;
    if (cnt > 3000) break;
  }

  if (cnt > 3000) {
    printf("-1\n");
  }
  else {
    printf("%d\n", cnt);
  }
}

int main()
{
  int rnd = 1;
  while (scanf("%d", &n) == 1 && n) {
    printf("Case %d: ", rnd);
    input();
    solve();

    rnd += 1;
  }
}
