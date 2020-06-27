// UVa 1588
#include <stdio.h>
#include <string.h>
#define MAXS 105
#define INF 1000
#define CEN 150

char s1[MAXS];
char s2[MAXS];
int n1, n2;

int get_height(int a, int b, int c, int d)
{
    int f = (a < c) ? c : a;
    int t = (b < d) ? b : d;
    int offset1 = f - c;
    int offset2 = f - a;
    int len = t - f;
    int h = 2;
    for (int i = 0; i < len; i++) {
        int c1 = s1[offset1 + i];
        int c2 = s2[offset2 + i];
        if (c1 == '1' && c2 == '1') h = h > 2 ? h : 2;
        else if (c1 == '2' && c2 == '2') h = h > 4 ? h : 4;
        else h = h > 3 ? h : 3;
        /* printf("   c1, c2, h %c %c %d\n", c1, c2, h); */
    }
    /* printf("f, t: %d %d offset1, offset2: %d %d len: %d\n", */
    /*        f, t, offset1, offset2, len); */
    if (h > 3) return INF;
    else return n1 + n2 - len;
}

void solve()
{
    n1 = strlen(s1);
    n2 = strlen(s2);
    int minl = n1 + n2;
    for (int i = -n2; i <= n1 + n2; i++) {
        int l = get_height(i, i+n2, 0, n1);
        minl = (l < minl) ? l : minl;
        /* printf("l = %d (%d %d %d %d)\n", l, i, i+n2, 0, n1); */
    }
    printf("%d\n", minl);
}

int main()
{
  while (scanf("%s", s1) == 1) {
    scanf("%s", s2);
    solve();
  }
}
