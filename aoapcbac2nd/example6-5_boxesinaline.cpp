#include <iostream>
#include <list>
using namespace std;

list<int> l;
int N, M;
long long S;


void init()
{
  l.clear();
  S = 0;
  for (int i = 1; i <= N; i++) {
    l.push_back(i);
  }
}

void trace()
{
  for (auto j = l.begin(); j != l.end(); j++) {
    printf("%d ", *j);
  }
  printf("\n");
}

void solve()
{
  int rev = 0;
  for (int i = 0; i < M; i++) {
    int instr, x, y;
    auto j = l.begin(), ix = l.begin(), iy = l.begin();
    scanf("%d", &instr);
    if (instr != 4) scanf("%d%d", &x, &y);

    for (j = l.begin(); j != l.end(); j++) {
      if (*j == x) ix = j;
      if (*j == y) iy = j;
    }

    if (instr == 1) { // move to left
        l.insert(iy, x);
        l.erase(ix);
    }
    else if (instr == 2) { // move to right
        iy++;
        l.insert(iy, x);
        l.erase(ix);
    }
    else if (instr == 3) { // swap
      int temp;
      temp = *ix;
      *ix = *iy;
      *iy = temp;
    }
    else if (instr == 4) { // reverse
      rev = (rev) ? 0 : 1;
    }
    else {
      ;
    }

    //trace();
  }


  if (!rev) {
    int i = 1;
    while (l.size() > 0) {
      //printf("%d ", l.front());
      if (i % 2 == 1) S += l.front();
      l.pop_front();

      i++;
    }
    //printf("\n");
  }
  else {
    int i = 1;
    while (l.size() > 0) {
      //printf("%d ", l.back());
      if (i % 2 == 1) S += l.back();
      l.pop_back();

      i++;
    }
    //printf("\n");
  }
}


int main()
{
  int rnd = 1;
  while (scanf("%d%d", &N, &M) == 2) {
    init();
    solve();
    printf("Case %d: %lld\n", rnd, S);

    rnd++;
  }

}
