#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int Q;
int c = 0;

void swap(char s[], int i, int j)
{
  char temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

char t[28];
int smaller(char x, char y)
{
  int ix = -1, iy = -1;
  for (int i = 0; i < 26; i++) {
    if (t[i] == x) ix = i;
    if (t[i] == y) iy = i;
  }
  if (ix < iy) return 1;
  else return 0;
}

void quicksort(char s[], int left, int right)
{
  if (left >= right) return;
  if (c >= Q) return;

  int pivot = (left + right) / 2;
  swap(s, pivot, left);
  int last = left;
  for (int i = left + 1; i <= right; i++) {
    if (c >= Q) return;
    if (i == last) continue;
    char ans;
    //cout << "? " << s[i] << " " << s[left] << endl;
    //cin >> ans;
    printf("? %c %c\n", s[i], s[left]);
    //printf("%d %d\n", i, left);
    fflush(stdout);
    //scanf(" %c", &ans); getchar();
    if (smaller(s[i], s[left])) ans = '<';
    else ans = '>';
    if (ans == '<') {
      swap(s, ++last, i);
    }
    c += 1;
    printf("c = %d\n", c);
  }
  swap(s, last, left);

  quicksort(s, left, last-1);
  quicksort(s, last+1, right);
}

void bsort(char s[], int N)
{
  int i, j;
  for(i=0;i<N;i++) for(j=0;j<N-1;j++){
    printf("? %c %c\n", s[j], s[j+1]);
    fflush(stdout);
    char ans;
    scanf(" %c", &ans);
    if(ans == '>') swap(s[j], s[j+1]);
  }
}


int main()
{
  int N;
  //cin >> N >> Q;
  scanf("%d%d", &N, &Q); getchar();
  scanf("%s", t); getchar();
  char s[N+1];
  for (int i = 0; i < N; i++) {
    s[i] = 'A' + i;
  }
  s[N] = '\0';
  //cout << s << endl;

  quicksort(s, 0, N-1);
  //bsort(s, N);

  cout << "! " << s << endl;
  fflush(stdout);
}
