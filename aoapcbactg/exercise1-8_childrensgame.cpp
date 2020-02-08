// UVa 10905
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50+5;
const int MAXC = 200;
string numbers[MAXN];
int N;


int main()
{
  while (scanf("%d", &N) != EOF) {
    if (N == 0) break;
    getchar();
    char str[MAXC];
    for (int i = 0; i < N; i++) {
      scanf("%s", str);
      numbers[i] = str;
    }

    sort(numbers, numbers+N);

    for (int i = N-1; i >=0; i--) {
      cout << numbers[i];
    }
    printf("\n");
  }
}
