#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000+10;
char S[MAXN];
vector<int> QBA;
int NQ;
int N;

int main()
{
  scanf("%s", S);
  for (int i = 0; S[i] != '\0'; i++) {
    if (S[i] == 'Q') NQ += 1;
    else if (S[i] == 'A') QBA.push_back(NQ);
    else ;
  }
  int sum = 0;
  for (int i = 0; i < QBA.size(); i++) {
    // printf("%d %d\n", QBA[i], NQ - QBA[i]);
    sum += (QBA[i] * (NQ - QBA[i]));
  }
  printf("%d\n", sum);
}
