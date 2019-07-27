#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXN 10005
#define INF 200000000
using namespace std;

struct node {
  int value;
  struct node *left;
  struct node *right;
};

node *root;
int inorder[MAXN];
int postorder[MAXN];
int A1, A2, N;
int best;
int bestindex;

node * insert(node **linkp, int value)
{
  node *e = (node *) malloc(sizeof(node));
  e->left = NULL;
  e->right = NULL;
  e->value = value;
  *linkp = e;
  return e;
}

void print(node *curr)
{
  if (curr == NULL) return;
  printf("%d ", curr->value);
  print(curr->left);
  print(curr->right);
}

void init()
{
  best = INF;
  bestindex = -1;
  root = NULL;
  A1 = A2 = 0;
  N = 0;
}

void trace()
{
  for (int i = A1; i < N; i++) {
    printf("%d", inorder[i]);
    (i == N-1) ? printf("\n") : printf(" ");
  }
  for (int i = A2; i < N; i++) {
    printf("%d", postorder[i]);
    (i == N-1) ? printf("\n") : printf(" ");
  }
}

void input()
{
  int c;
  int i = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
    ungetc(c, stdin);
    scanf("%d", &inorder[i++]);
  }
  i = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
    ungetc(c, stdin);
    scanf("%d", &postorder[i++]);
  }
  N = i;
}

void build(node **linkp, int a1, int a2, int n, int sum)
{
  if (n <= 0) {
    return;
  }
  int rvalue = postorder[a2+n-1];
  int rindex = -1;
  for (int i = a1; i < n+a1; i++) {
    // printf("inorder: %d %d ? %d\n", inorder[i], rvalue, (inorder[i] == rvalue));
    if (inorder[i] == rvalue) {
      rindex = i;
      break;
    }
  }
  // if (rindex == -1) {
  //   printf("%d %d %d %d %d ", rvalue, rindex, a1, a2, n);
  //   printf("error\n");
  //   return;
  // }
  // printf("rindex: %d\n", rindex);
  node *e = insert(linkp, rvalue);
  sum += e->value;

  int len1 = rindex - a1;
  int len2 = n - len1 - 1;

  if (len1 <= 0 && len2 <= 0 && sum < best) { best = sum; bestindex = e->value; }

  // printf("%d %d %p\n", rvalue, rindex, e);
  // printf("len1: %d len2: %d\n", len1, len2);
  // printf("(%d %d) (%d %d)\n", a1, a1+len1-1, a2, a2+len1-1);
  // printf("(%d %d) (%d %d)\n", rindex+1, rindex+1+len2-1, a1+len1, a1+len1+len2-1);
  build(&e->left, a1, a2, len1, sum);
  build(&e->right, rindex+1, a2+len1, len2, sum);
}


int main()
{
  int c;
  while ((c = getchar()) != EOF) {
    ungetc(c, stdin);
    init();
    input();
    //trace();
    build(&root, A1, A2, N, 0);
    //print(root); printf("\n");
    //printf("%d %d\n", best, bestindex);
    printf("%d\n", bestindex);
  }
}
