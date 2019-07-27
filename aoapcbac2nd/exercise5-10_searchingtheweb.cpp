#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <cctype>
#define MAXN 105
//#define MAXS 1500
//#define MAXC 80
#define MAXL 20
using namespace std;

string docs[MAXN][MAXL];
int N, M;

void trace()
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; docs[i][j] != ""; j++) {
      cout << docs[i][j] << endl;
    }
    cout << "**********\n";
  }
  cout << "\n";
}

void input()
{
  scanf("%d", &N); getchar();
  string s;
  for (int i = 0; i < N; i++) {
    int l = 0;
    while (getline(cin, s)) {
      if (s[0] == '*' && s[9] == '*') break;

      docs[i][l] = s;

      l++;
    }
    s = "";
    docs[i][l] = s;
  }
}

int breakdown(string& s1, string& s2)
{
  string s, a, b, c;
  getline(cin, s);
  stringstream ss(s);
  ss >> a;
  ss >> b;
  ss >> c;

  if (a == "NOT") {
    s1 = b; s2 = "";
    return 3;
  }
  else if (b == "AND") {
    s1 = a; s2 = c;
    return 1;
  }
  else if (b == "OR") {
    s1 = a; s2 = c;
    return 2;
  }
  else {
    s1 = a; s2 = "";
    return 0;
  }
}

void printwhole(int x)
{
  for (int i = 0; docs[x][i] != ""; i++) {
    cout << docs[x][i] << endl;
  }
}

void execute(string& s1, string& s2, int op)
{
  // 0, AND: 1, OR: 2, NOT, 3
  int founddoc = 0, first = 1;
  for (int i = 0; i < N; i++) {
    //printf("D%d:\n", i);
    vector<int> lines;
    int foundword = 0, found1 = 0, found2 = 0;
    for (int j = 0; docs[i][j] != ""; j++) {
      string buff;
      for (int k = 0; k < docs[i][j].size(); k++) {
        buff.push_back(tolower(docs[i][j][k]));
      }

      int p1 = buff.find(s1);
      int p2 = (s2 != "") ? buff.find(s2) : -1;
      if (op == 3 && p1 >= 0) {
        founddoc = 1;
        foundword = 1;
        break;
      }
      else if (op == 2 && (p1 >= 0 || p2 >= 0)) {
        founddoc = 1;
        //printf("%d\n", j);
        lines.push_back(j);
      }
      else if (op == 1 && (p1 >= 0 || p2 >= 0)) {
        founddoc = 1;
        if (p1 >= 0) found1 = 1;
        if (p2 >= 0) found2 = 1;
        //printf("%d\n", j);
        lines.push_back(j);
      }
      else if (op == 0 && p1 >= 0) {
        founddoc = 1;
        found1 = 1;
        //printf("%d\n", j);
        lines.push_back(j);
      }
    }

    if (op == 3 && foundword == 0) {
      if (first == 0) cout << "----------\n";
      if (first) first = 0;
      printwhole(i);
    }
    else if (op == 2 && lines.size() > 0) {
      if (first == 0) cout << "----------\n";
      if (first) first = 0;
      for (int k = 0; k < lines.size(); k++) cout << docs[i][lines[k]] << endl;
    }
    else if (op == 1 && found1 && found2) {
      if (first == 0) cout << "----------\n";
      if (first) first = 0;
      for (int k = 0; k < lines.size(); k++) cout << docs[i][lines[k]] << endl;
    }
    else if (op == 0 && found1) {
      if (first == 0) cout << "----------\n";
      if (first) first = 0;
      for (int k = 0; k < lines.size(); k++) cout << docs[i][lines[k]] << endl;
    }
    else {
      ;
    }

    lines.resize(0);
  }

  if (founddoc == 0) cout << "Sorry, I found nothing.\n";

}

int main()
{
  input();
  //trace();
  scanf("%d", &M); getchar();
  string q, s1, s2;
  for (int i = 0; i < M; i++) {
    //printf("Q%d:\n", i);
    int op = breakdown(s1, s2);
    execute(s1, s2, op);
    cout << "==========\n";
  }
}
