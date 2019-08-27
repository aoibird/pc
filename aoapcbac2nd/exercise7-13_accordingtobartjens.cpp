#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

const int MAXSIZE = 100;

char digits[MAXSIZE];
char ops[MAXSIZE];
int S;
char expr[MAXSIZE*2];
int T;
vector<string> allexpr;


char op[5] = {'\0', '+', '-', '*', '/'};

int cal(int n1, char op, int n2)
{
  if (op == '+') {
    return n1 + n2;
  }
  else if (op == '-') {
    return n1 - n2;
  }
  else if (op == '*') {
    return n1 * n2;
  }
  else if (op == '/') {
    return n1 / n2;
  }
  else {
    printf("%d %d %d\n", n1, op, n2);
    assert(0);
  }
}

void print_expr()
{
  for (int i = 0; i < T; i++) {
    printf("%c", expr[i]);
  }
}

int read_expr()
{
  T = 0;
  for (int i = 0; i < S; i++) {
    expr[T] = digits[i]; T++;
    if (ops[i] != '\0') { expr[T] = ops[i]; T++; }
  }
  expr[T] = '\0';
  string temp = expr;
  // if (temp == "2*10-0*100=" || temp == "2*10+0*100=") printf("///\n");



  stack<char> op;
  stack<int> dig;
  int i = 0;
  char number[MAXSIZE];
  while (1) {
    // digit
    int t = 0;
    while (isdigit(expr[i])) {
      number[t++] = expr[i++];
    }
    number[t++] = '\0';
    if (strlen(number) != 1 && number[0] == '0') return 0;
    else dig.push(atoi(number));
    if (expr[i] == '=') break;

    // op
    if (op.empty()) {
      op.push(expr[i]);
      i++;
    }
    else if ((expr[i] == '*' || expr[i] == '/')
             && (op.top() == '+' || op.top() == '-')) {
      op.push(expr[i]);
      i++;
    }
    else {
      char o = op.top(); op.pop();
      int n2 = dig.top(); dig.pop();
      int n1 = dig.top(); dig.pop();
      if (o == '/' && n2 == 0) return 0;
      int res = cal(n1, o, n2);
      dig.push(res);
      // if (temp == "2*10-0*100=" || temp == "2*10+0*100=")
      //   printf("%d = %d %c %d\n", res, n1, o, n2);

      op.push(expr[i]);
      i++;
    }
  }

  while (!op.empty()) {
    char o = op.top(); op.pop();
    int n2 = dig.top(); dig.pop();
    int n1 = dig.top(); dig.pop();
    if (o == '/' && n2 == 0) return 0;
    int res = cal(n1, o, n2);
    dig.push(res);
  }

  if (dig.top() == 2000) return 1;
  else return 0;
}

void dfs(int curr)
{
  if (digits[curr+1] == '=') {
    ops[curr] = '\0';
    int ok = read_expr();
    if (ok) {
      string e = expr;
      allexpr.push_back(e);
    }
    return;
  }

  for (int i = 0; i < 5; i++) {
    ops[curr] = op[i];
    dfs(curr+1);
  }
}


int main()
{
  int tc = 1;
  while (scanf("%s", digits) == 1) {
    if (digits[0] == '=') break;

    S = strlen(digits);

    memset(ops, 0, sizeof(ops));
    allexpr.resize(0);


    dfs(0);
    sort(allexpr.begin(), allexpr.end());

    printf("Problem %d\n", tc);
    if (allexpr.size() == 0) {
      printf("  IMPOSSIBLE\n");
    }
    else {
      for (int i = 0; i < allexpr.size(); i++) {
        printf("  ");
        cout << allexpr[i] << "\n";
      }
    }
  }
}
