#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int DS = 5;
const int MAXN = 1000000000+10;
int M;
int S;
int D[DS] = {100, 20, 10, 5, 1};

int main()
{
  scanf("%d", &M);

  for (int i = 0; i < DS && M > 0; i++) {
    if (M >= D[i]) {
      int s = M / D[i];
      S += s;
      M -= (s * D[i]);
    }
  }
  printf("%d\n", S);
}

