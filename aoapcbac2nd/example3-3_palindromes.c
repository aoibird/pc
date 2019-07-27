#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000

char m[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char str[MAX];

int get_mirror(char s)
{
  if (isalpha(s)) return m[s - 'A'];
  else return m[s - '0' + 25];
}

void solve()
{
  int palindrome = 1;
  int mirror = 1;
  int n = strlen(str);
  for (int i = 0; i < (n+1) / 2; i++) {
    if (str[i] != str[n-i-1]) {
      //printf("p: %c %c\n", str[i], str[n-i-1]);
      palindrome = 0;
    }
    if (get_mirror(str[i]) != str[n-i-1]) {
      //printf("m: %c %c\n", str[i], str[n-i-1]);
      mirror = 0;
    }
  }

  printf("%s -- ", str);
  if (mirror == 1 && palindrome == 1) {
    printf("is a mirrored palindrome.\n");
  }
  else if (mirror == 1 && palindrome == 0) {
    printf("is a mirrored string.\n");
  }
  else if (mirror == 0 && palindrome == 1) {
    printf("is a regular palindrome.\n");
  }
  else {
    printf("is not a palindrome.\n");
  }
}

int main()
{
  while (scanf("%s", str) == 1) {
    solve();
    printf("\n");
  }



}
