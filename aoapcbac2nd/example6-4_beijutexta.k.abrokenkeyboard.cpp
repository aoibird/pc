#include <iostream>
#include <cstdio>
using namespace std;

int last, n;

struct node {
  char ch;
  struct node *next;
};

void insert(node **linkp, char c, int p)
{
  node *curr;
  int i = 0;
  while ((curr = *linkp) != NULL && i < p) {
    linkp = &curr->next;
    i++;
  }

  node *e = (node *) malloc(sizeof(node));
  e->next = curr;
  e->ch = c;
  *linkp = e;

  n++;
}

void destroy(node **linkp)
{
  node *curr;
  while ((curr = *linkp) != NULL) {
    *linkp = curr->next;
    free(curr);
  }
}

void print(node **linkp)
{
  node *curr;
  while ((curr = *linkp) != NULL) {
    printf("%c", curr->ch);
    linkp = &curr->next;
  }
  printf("\n");
}

void solve()
{
  n = 0;
  last = 0;

  int c;
  node *root = NULL;
  while ((c = getchar()) != '\n' && c != EOF) {
    //printf("%c --", (char)c);
    //print(&root);
    if (c == '[') last = 0;
    else if (c == ']') last = n;
    else {
      insert(&root, c, last);
      last++;
    }
  }

  print(&root);

  destroy(&root);
}



int main()
{
  int c;
  while ((c = getchar()) != EOF) {
    ungetc(c, stdin);
    solve();
  }
}
