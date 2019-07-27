#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <queue>
#include <cstring>
#define MAXC 5000
#define MAXD 300
using namespace std;

int value;
char direct[MAXD];
int n, m;

struct node {
  bool exist;
  int value;
  struct node *left;
  struct node *right;
};

node *root;

void insert()
{
  node **linkp = &root;
  node *curr = root;
  int i = 0;
  while (direct[i] != '\0') {
    curr = *linkp;
    if (curr == NULL) {
      node * e = (node *) malloc(sizeof(node));
      e->left = NULL;
      e->right = NULL;
      e->exist = false;
      *linkp = e;
      curr = e;
      m++;
    }

    if (direct[i] == 'L') linkp = &curr->left;
    else linkp = &curr->right;

    i++;
  }
  curr = *linkp;

  if (curr != NULL) {
    curr->value = value;
    curr->exist = true;
  }
  else {
    node *e = (node *) malloc(sizeof(node));
    e->value = value;
    e->exist = true;
    e->left = NULL;
    e->right = NULL;
    *linkp = e;
    m++;
  }

}

void destroy(node *r)
{
  if (r == NULL) return;
  destroy(r->left);
  destroy(r->right);
  free(r);
}

void trace()
{
  printf("%d : ", value);
  for (int i = 0; direct[i] != '\0'; i++) printf("%c", direct[i]);
  printf("\n");
}

void input(char *s)
{
  root = NULL;
  n = 0, m = 0;
  int i = 0, t;
  char buff[MAXD];
  //printf("%s\n", s);
  while (s[i] != '\0') {
    while (s[i] != '(') i++;
    if (s[i+1] == ')') break;
    i++;

    // read value
    t = 0;
    while (!isdigit(s[i])) i++;
    while (isdigit(s[i])) buff[t++] = s[i++];
    i++; buff[t] = '\0';
    value = atoi(buff);

    // read direct
    t = 0;
    while (s[i] != ')') direct[t++] = s[i++];
    i++; direct[t] = '\0';

    insert();
    n++;

    //trace();
  }
}

void solve()
{
  //printf("%d %d\n", n, m);
  //printf("%p\n", root);
  if (n != m) {
    printf("not complete\n");
    return;
  }

  queue<node *> q;
  q.push(root);
  while (!q.empty()) {
    node *e = q.front(); q.pop();
    if (e != root) printf(" ");
    printf("%d", e->value);

    if (e->left != NULL) q.push(e->left);
    if (e->right != NULL) q.push(e->right);
  }
  printf("\n");

}

int main()
{
  char s[MAXC];
  int c;
  while ((c = getchar()) != EOF) {
    ungetc(c, stdin);
    char *p = s;
    while (scanf("%s", p) == 1) {
      int len = strlen(s);
      if ((len + s) - p == 2) break;
      p = len + s;
    }
    getchar();

    input(s);
    solve();
    destroy(root);
  }
}
