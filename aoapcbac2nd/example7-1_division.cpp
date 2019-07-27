#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int NUMBERS = 10;
const int K = 5;
int N;

int perm[K]; // pos [0, K)
bool used[NUMBERS]; // [0, 9]
int cnt;
int ok;

void permulation(int pos)
{
  if (pos == K) {
    // for (int i = 0; i < K; i++) printf("%d ", perm[i]);
    // cnt++;
    // printf("%d\n", cnt);

    char buff[NUMBERS*2];

    // y
    int i;
    for (i = 0; i < K; i++) buff[i] = perm[i]+'0';
    buff[i] = '\0';
    int y = atoi(buff);

    // x
    int x = y * N;
    sprintf(buff, "%05d%05d", x, y);

    // count
    if (strlen(buff) > NUMBERS) return;

    int num[NUMBERS];
    memset(num, 0, sizeof(num));
    //for (int i = 0; i < NUMBERS; i++) ;
    for (int i = 0; buff[i] != '\0'; i++) {
      int t = buff[i]-'0';
      num[t] += 1;
      if (num[t] > 1) return;
    }

    ok = 1;
    printf("%05d / %05d = %d\n", x, y, N);

    return;
  }

  for (int i = 0; i < NUMBERS; i++) {
    if (!used[i]) {
      perm[pos] = i;
      used[i] = true;
      permulation(pos+1);
      used[i] = false;
    }
  }
  return;
}

int main()
{

  int first = 1;
  while (scanf("%d", &N) == 1 && N) {
    // cnt = 0;
    if (first) first = 0;
    else printf("\n");

    for (int i = 0; i < K; i++) used[i] = false;
    ok = 0;
    permulation(0);
    if (!ok) printf("There are no solutions for %d.\n", N);

    //printf("%d\n", cnt);
  }

}
