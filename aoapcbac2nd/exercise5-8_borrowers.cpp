#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define MAXS 100
using namespace std;

typedef pair<string, string> P;
vector<P> shelves;
vector<P> borrow;
vector<P> temp;

void trace()
{
  for (int i = 0; i < shelves.size(); i++) {
    cout << shelves[i].first << " " << shelves[i].second << endl;
  }
}

void input()
{
  string s, title, author;
  char buff[MAXS];
  while (getline(cin, s)) {
    //cout << "s: " << s << endl;
    if (s == "END") break;

    int p = 1, t = 0;
    while (s[p] != '"') {
      buff[t++] = s[p++];
    }
    buff[t] = '\0';
    title = buff;
    while (s[p] != 'b' && s[p+1] != 'y') p++;
    p += 3;
    t = 0;
    while (p < s.size()) buff[t++] = s[p++];
    buff[t] = '\0';
    author = buff;

    shelves.push_back(P(author, title));
  }
  sort(shelves.begin(), shelves.end());

  //trace();
}

void execute()
{
  string s, title, author;
  char buff[MAXS];
  while (getline(cin, s)) {
    //cout << s << endl;
    if (s == "END") break;

    int t = 0;
    for (int i = 8; i < s.size()-1; i++, t++) {
      buff[t] = s[i];
      //printf("%c %c\n", buff[t], s[i]);
    }
    buff[t] = '\0';
    title = buff;
    //cout << buff << " | " << title << endl;

    if (s[0] == 'B') {
      int i;
      for (i = 0; i < shelves.size(); i++) {
        if (shelves[i].second == title) {
          author = shelves[i].first;
          break;
        }
      }

      shelves.erase(shelves.begin()+i);
      borrow.push_back(P(author, title));
    }
    else if (s[0] == 'R') {
      int i;
      for (i = 0; i < borrow.size(); i++) {
        if (borrow[i].second == title) {
          author = borrow[i].first;
          break;
        }
      }

      temp.push_back(P(author, title));
      borrow.erase(borrow.begin()+i);
    }
    else if (s[0] == 'S') {
      sort(temp.begin(), temp.end());
      for (int i = 0; i < temp.size(); i++) {
        P e = temp[i];
        int p = lower_bound(shelves.begin(), shelves.end(), e) - shelves.begin();
        shelves.insert(shelves.begin()+p, e);
        if (p != 0)
          cout << "Put \"" << e.second << "\" after \"" << shelves[p-1].second << "\"\n";
        else
          cout << "Put \"" << e.second << "\" first\n";
      }
      cout << "END\n";
    }
    else {
      ;
    }
  }
}

int main()
{
  input();
  execute();
}
