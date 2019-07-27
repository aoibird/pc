#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAXM 100005
using namespace std;

bool memory[MAXM]; // [1, m]
int n, m, q;
vector<pair<int, int> > v;

void trace()
{
  cout << "input: ";
  for (int i = 1; i <= m; i++) {
    cout << memory[i] << " ";
  }
  cout << endl;
  printf("%d %d %d\n", n, m, q);

  for (int i = 0; i < v.size(); i++) {
    int r, l;
    r = v[i].first;
    l = v[i].second;
    printf("%d %d\n", r, l);
  }
  printf("\n");
}

void findall()
{
  //printf("find: %d\n", x);
  int r = m;
  int l = m;
  while (1) {
    //printf("l, r: %d %d %d %d\n", l, r, memory[l], memory[r]);
    while (r > 0 && memory[r] == true) r--;
    l = r;
    while (l > 0 && memory[l] == false) l--;
    //printf("l, r: %d %d %d %d\n", l, r, memory[l], memory[r]);

    if (r == 0) {
      return;
    }

    v.push_back(make_pair(r, l+1));
    r = l;
  }
}

void input()
{
  // space
  cin >> n >> m >> q;
  memset(memory, 0, sizeof(memory));
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j <= r; j++) {
      memory[j] = true;
    }
  }

  v.clear();

  findall();
  sort(v.begin(), v.end());

  //trace();
}

void find(int x, int& from, int& to)
{
  for (int i = v.size() - 1; i >= 0; i--) {
    int r = v[i].first;
    int l = v[i].second;
    //printf("l, r: %d %d\n", l, r);
    if (r - x + 1 < l) {
      continue;
    }
    else {
      from = r - x + 1;
      to = r;
      return;
    }
  }

  from = -1;
  to = -1;
  return;
}


void solve()
{
  //query
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    int from, to;
    find(x, from, to);
    cout << from << " " << to << "\n";
  }

}

int main()
{
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    input();
    solve();
  }
}
