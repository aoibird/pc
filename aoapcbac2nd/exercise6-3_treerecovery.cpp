#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 30
using namespace std;

struct node {
  char ch;
  struct node *left;
  struct node *right;
};

char preorder[MAXN];
char inorder[MAXN];
node *root;

node *insert(node **rootp, char ch)
{
  node * e = (node *) malloc(sizeof(node));

  e->ch = ch;
  e->left = NULL;
  e->right = NULL;

  *rootp = e;
  return e;
}

void build(node **rp, int spre, int sin, int len)
{
  if (len <= 0) return;
  char rvalue = preorder[spre];
  int rindex = -1;
  for (int i = sin; i < sin+len; i++) {
    if (rvalue == inorder[i]) rindex = i;
  }
  node * e = insert(rp, rvalue);

  int lenleft = rindex - sin;
  int lenright = len - lenleft - 1;

  build(&e->left, spre+1, sin, lenleft);
  build(&e->right, spre+1+lenleft, rindex+1, lenright);

}

void postorder(node *r)
{
  if (r == NULL) return;

  postorder(r->left);
  postorder(r->right);
  printf("%c", r->ch);
}

int main()
{
  while (scanf("%s %s", preorder, inorder) == 2) {
    root = NULL;
    int len = strlen(preorder);
    build(&root, 0, 0, len);

    postorder(root);
    printf("\n");
  }
}
