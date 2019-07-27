#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#define MAXS 85
#define MAXR 10005
#define MAXC 15
using namespace std;

map<string, int> strid;
//set<int> strid;
map<pair<int, int>, int > idpair;
int R, C;
int table[MAXR][MAXC];

void printtable()
{
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << table[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void input()
{
  char buff[MAXS];
  string s;
  int l;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int c;
      l = 0;
      while ((c = getchar()) != ',' && c != '\n') buff[l++] = c;
      buff[l++] = '\0';
      s = buff;
      if (strid[s] == 0) strid[s] = j + i * R;
      table[i][j] = strid[s];

      //printf("%s(%d)    ", buff, strid[s]);
    }
    //printf("\n");
  }

  //printtable();
}

void solve()
{
  int ok = 0;
  int r1, r2, r, c1, c2;
  for (r = 0; r < R; r++) {
    for (c1 = 0; c1 < C; c1++) {
      for (c2 = c1+1; c2 < C; c2++) {
        pair<int, int> vp = make_pair(table[r][c1], table[r][c2]);
        if (idpair.count(vp) == 0) idpair[vp] = r;
        else {
          ok = 1;
          r1 = idpair[vp];
          r2 = r;
          break;
        }
      }
      if (ok) break;
    }
    if (ok) break;
  }
  if (ok) {
    printf("NO\n");
    printf("%d %d\n%d %d\n", r1+1, r2+1, c1+1, c2+1);
    //printf("%d %d %d %d\n", table[r1][c1], table[r1][c2], table[r2][c1], table[r2][c2]);
  }
  else {
    printf("YES\n");
  }
}

void destroy()
{
  strid.clear();
  idpair.clear();
}

int main()
{
  while(cin >> R >> C) {
    getchar();
    input();
    solve();
    destroy();
  }
}
