#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 30
using namespace std;

vector<int> blocks[MAXN];
int n;
int ax, ay;
int bx, by;

void find_block(int a, int b)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < blocks[i].size(); j++) {
      if (blocks[i][j] == a) {
        ax = i;
        ay = j;
      }
      else if (blocks[i][j] == b) {
        bx = i;
        by = j;
      }
      else {
        ;
      }
    }
  }
}

void clear_block(int x, int y)
{
  for (int i = y+1; i < blocks[x].size(); i++) {
    int value = blocks[x][i];
    blocks[value].push_back(value);
  }
}

void pile()
{
  for (int y = ay; y < blocks[ax].size(); y++) {
    int value = blocks[ax][y];
    blocks[bx].push_back(value);
  }
  blocks[ax].resize(ay);
}

void print()
{
  for (int i = 0; i < n; i++) {
    printf("%d:", i);
    for (int j = 0; j < blocks[i].size(); j++) {
      printf(" %d", blocks[i][j]);
    }
    printf("\n");
  }
}


int main()
{
  cin >> n;
  string s1, s2;
  int a, b;
  for (int i = 0; i < n; i++) {
    blocks[i].push_back(i);
  }
  while (cin >> s1 >> a >> s2 >> b) {
    //cout << s1 << " " << a << " " << s2 << " " << b << endl;
    find_block(a, b);
    //printf("%d %d %d %d\n", ax, ay, bx, by);

    if (ax == bx) continue; // illegal

    if (s1 == "move") clear_block(ax, ay);
    else if (s2 == "onto") clear_block(bx, by);
    pile();
    //print();
  }

  print();
}
