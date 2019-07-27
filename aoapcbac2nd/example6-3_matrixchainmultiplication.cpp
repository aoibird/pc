#include <iostream>
#include <cstdio>
#include <stack>
#include <map>
using namespace std;

typedef pair<int, int> P;
map<int, P> m;
int N;

void input()
{
  scanf("%d", &N); getchar();
  for (int i = 0; i < N; i++) {
    char ch = getchar();
    int l, c;
    scanf("%d%d", &l, &c); getchar();
    m[ch-'A'] = P(l, c);
  }
}


int main()
{
  stack<char> s;
  input();

  int c, newm = 26;
  int i = 0;
  while ((c = getchar()) != EOF) {
    ungetc(c, stdin);

    long long sum = 0;
    int ok = 1;
    //printf("i: %d\n", i);
    while ((c = getchar()) != '\n') {
      if (c != '(' && c != ')') s.push(c-'A');
      else if (c == ')') {
        int index2 = s.top(); s.pop();
        int index1 = s.top(); s.pop();
        P e1 = m[index1];
        P e2 = m[index2];
        if (e1.second == e2.first) {
          sum += (e1.first * e1.second * e2.second);
          newm++;
          m[newm] = P(e1.first, e2.second);
          s.push(newm);
        }
        else {
          ok = 0;
          while ((c = getchar()) != '\n') ;
          ungetc(c, stdin);
        }
      }
      else ;
    }

    if (ok) {
      printf("%lld\n", sum);
    }
    else {
      printf("error\n");
    }
    while (!s.empty()) s.pop();

    i++;
  }

}
