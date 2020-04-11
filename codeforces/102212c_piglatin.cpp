#include <iostream>
#include <stdio.h>
#include <ctype.h>
#define MAX 1000
using namespace std;

void piglatin(string& s)
{
  getline(cin, s);

  int i = 0, j = 0;
  while (j < s.size()) {
    while (s[i] == ' ') i++;
    j = i;
    while (s[j] != ' ' && j < s.size()) j++;

    char buff[4] = {'?', 'a', 'y', '\0'};
    buff[0] = tolower(s[i]);
    string ins = buff;
    s.insert(j, buff);
    if (isupper(s[i])) s.replace(i+1, 1, 1, toupper(s[i+1]));
    s.erase(i, 1);
    j += 3;
    i = j;
  }

  /*
  int i = 0;
  int ch;
  string ins;
  bool upper = false;

  while (i < s.size()) {
    //cout << s << " " << i << " ";
    while (s[i] == ' ') i++;
    if (isupper(s[i])) {
      upper = true;
      ch = tolower(s[i]);
    }
    else {
      upper = false;
      ch = s[i];
    }
    //cout << s[i] << endl;

    s.erase(i, 1);
    char buff[4] = {'?', 'a', 'y', '\0'};
    if (upper && s[i] != ' ') {
      buff[0] = tolower(ch);
      s.replace(i, 1, 1, toupper(s[0]));
    }
    else buff[0] = ch;
    ins = buff;

    if (s[i] == ' ') {
      s.insert(i, ins);
      s.replace(i, 1, 1, toupper(ch));
      i += 3;
    }
    else {
      while (s[i] != ' ' && i < s.size()) i++;
      s.insert(i, ins);
      i += 3;
    }
  }
  */
}

int main()
{
  int n;
  cin >> n;
  cin.ignore();
  string s;
  for (int i = 0; i < n; i++) {
    piglatin(s);
    cout << s << endl;
  }
}
