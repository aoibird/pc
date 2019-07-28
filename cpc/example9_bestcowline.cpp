#include <iostream>
#define MAXN 2005
using namespace std;


int main()
{
  int n;
  cin >> n;
  char s[MAXN];
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    s[i] = c;
  }

  int a = 0, b = n - 1;
  while (a <= b) {
    bool left = false;
    for (int i = 0; a + i <= b; i++) {
      if (s[a + i] < s[b - i]) {
        left = true;
        break;
      }
      else if (s[a + i] > s[b - i]) {
        left = false;
        break;
      }
      else {
        ;
      }

    }

    if (left) putchar(s[a++]);
    else putchar(s[b--]);
    // if (left) {
    //   printf("%c", s[a]);
    //   a++;
    // }
    // else {
    //   printf("%c", s[b]);
    //   b--;
    // }
  }
  //putchar('\n');
  // printf("\n");

  return 0;
}
