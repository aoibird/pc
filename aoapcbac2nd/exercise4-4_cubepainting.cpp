#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

const int L = 10;
char c1[L], c2[L];
pii p1[3], p2[3];

bool cmp(pii &a, pii &b)
{
    return a.first<b.first||(a.first==b.first&&a.second==b.second);
}

bool solve()
{
    for (int i = 0; i < 6; i++)
        p1[i] = pii(min(c1[i], c1[5-i]), max(c1[i], c1[5-i]));
    for (int i = 0; i < 6; i++)
        p2[i] = pii(min(c2[i], c2[5-i]), max(c2[i], c2[5-i]));
    sort(p1, p1+3, cmp);
    sort(p2, p2+3, cmp);

    for (int i = 0; i < 3; i++)
        if (p1[i] != p2[i]) return false;
    return true;
}

int main()
{
  while (scanf("%6s%6s", c1, c2) == 2) {
      if (solve()) printf("TRUE\n");
      else printf("FALSE\n");
  }
}
