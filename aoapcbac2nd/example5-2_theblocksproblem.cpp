// UVa 101
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 30
using namespace std;

vector<int> blocks[MAXN];
int n;

void find_block(int a, int &p, int &h)
{
    for (p = 0; p < n; p++) {
        for (h = 0; h < blocks[p].size(); h++) if (blocks[p][h] == a) return;
    }
}

void clear_block(int p, int h)
{
  for (int i = h+1; i < blocks[p].size(); i++) {
    int b = blocks[p][i];
    blocks[b].push_back(b);
  }
  blocks[p].resize(h+1);
}

void pile_onto(int p, int h, int p2)
{
  for (int i = h; i < blocks[p].size(); i++) blocks[p2].push_back(blocks[p][i]);
  blocks[p].resize(h);
}

void print()
{
  for (int i = 0; i < n; i++) {
    printf("%d:", i);
    for (int j = 0; j < blocks[i].size(); j++) printf(" %d", blocks[i][j]);
    printf("\n");
  }
}


int main()
{
  cin >> n;
  string s1, s2;
  int a, b;
  for (int i = 0; i < n; i++) blocks[i].push_back(i);

  while (cin >> s1 >> a >> s2 >> b) {
    int pa, pb, ha, hb;
    find_block(a, pa, ha);
    find_block(b, pb, hb);

    if (pa == pb) continue; // illegal

    if (s2 == "onto") clear_block(pb, hb);
    if (s1 == "move") clear_block(pa, ha);
    pile_onto(pa, ha, pb);
  }

  print();
}
