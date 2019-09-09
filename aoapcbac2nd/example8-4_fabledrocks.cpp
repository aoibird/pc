// UVa 11134
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct Block {
  int num;
  int r1;
  int c1;
  int r2;
  int c2;
  int r;
  int c;
  Block(int n=0, int a=0, int b=0, int c=0, int d=0, int rd=0, int cd=0) {
    num = n;
    r1 = a;
    c1 = b;
    r2 = c;
    c2 = d;
    r = rd;
    c = cd;
  }
};

const int MAXN = 5000+10;
Block B[MAXN];
int V[MAXN];
int N;

bool compare(Block a, Block b)
{
  int sa = a.c1*1000 + a.r1*100 + a.c2*10 + a.r2;
  int sb = b.c1*1000 + b.r1*100 + b.c2*10 + b.r2;
  if (sa < sb) return true;
  else return false;
}

bool compare_number(Block a, Block b)
{
  if (a.num < b.num) return true;
  else return false;
}

void print()
{
  for (int i = 0; i < N; i++) {
    printf("%d: %d~%d %d~%d\n", B[i].num, B[i].r1, B[i].r2, B[i].c1, B[i].c2);
  }
}

void check()
{
  for (int i = 0; i < N; i++) {
    if (B[i].r < B[i].r1 || B[i].r > B[i].r2
        || B[i].c < B[i].c1 || B[i].c > B[i].c2) {
      printf("FAILED: %d:%d~%d %d:%d~%d\n",
             B[i].r, B[i].r1, B[i].r2,
             B[i].c, B[i].c1, B[i].c2);
    }
  }
}

int main()
{
  while (scanf("%d", &N) == 1) {
    // input
    if (N == 0) break;
    for (int i = 0; i < N; i++) {
      B[i].num = i+1;
      scanf("%d%d%d%d", &B[i].r1, &B[i].c1, &B[i].r2, &B[i].c2);
    }



    sort(B, B+N, compare);
    //print();
    memset(V, 0, sizeof(V));
    int failed = 0;
    for (int i = 0; i < N; i++) {
      if (B[i].c1 > i+1) {
        //printf("%d %d", B[i].c1, i+1);
        failed = 1;
        break;
      }
      B[i].c = i+1;
      int ok = 0;
      for (int j = B[i].r1; j <= B[i].r2; j++) {
        if (V[j] == 0) {
          V[j] = 1;
          B[i].r = j;
          ok = 1;
          //printf("%d\n", B[i].r);
          break;
        }
      }

      //printf("%d,%d: (%d, %d)\n", i, B[i].num, B[i].r, B[i].c);
      if (ok == 0) { failed = 1; break; }
    }

    // check
    // check();

    // print
    if (failed == 1) printf("IMPOSSIBLE\n");
    else {
      sort(B, B+N, compare_number);
      for (int i = 0; i < N; i++) {
        printf("%d %d\n", B[i].r, B[i].c);
      }
    }
  }
}
