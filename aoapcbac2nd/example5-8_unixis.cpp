#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> names;
int n;

void input()
{
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    names.push_back(s);
  }
  sort(names.begin(), names.end());
}

void solve()
{
  int maxl = names[0].size();
  for (int i = 1; i < names.size(); i++) {
    int l = names[i].size();
    if (l > maxl) maxl = l;
  }

  int col = 62 / (maxl + 2);
  int row = ceil(n / (double) col);

  printf("------------------------------------------------------------\n");
  // printf("row: %d col: %d n: %d\n", row, col, n);

  for (int j = 0; j < row; j++) {
    for (int i = 0; i < col; i++) {
      if (j+i*row < names.size()) {
        //cout << names[j+i*row] << "(" << j+i*row << ")  ";
        cout << names[j+i*row];
        int r = maxl - names[j+i*row].size();
        for (int i = 0; i < r; i++) printf(" ");
        if (i != col-1) printf("  ");
      }
    }
    cout << endl;
  }
  //printf("------------------------------------------------------------\n");
  names.resize(0);
}


int main()
{
  while (cin >> n) {
    input();
    solve();
  }
}
