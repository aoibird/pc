#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAXS 100
using namespace std;

typedef pair<string, string> P;
vector<P> dict1;
vector<P> dict2;
vector<string> change;
vector<string> del;
vector<string> inc;

void trace()
{
  for (int i = 0; i < dict1.size(); i++) {
    cout << dict1[i].first << " " << dict1[i].second << endl;
  }

  for (int i = 0; i < dict2.size(); i++) {
    cout << dict2[i].first << " " << dict2[i].second << endl;
  }
  cout << endl;

}

void input()
{
  dict1.resize(0);
  dict2.resize(0);
  change.resize(0);
  del.resize(0);
  inc.resize(0);
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  //cout << s1 << " " << s2 << endl;

  int p1 = 1, p2 = 1;
  char buff[MAXS];
  string key, value;

  while (p1 < s1.size()) {
    int t;
    // get key
    t = 0;
    while (s1[p1] != ':') buff[t++] = s1[p1++];
    buff[t] = '\0';
    key = buff;
    p1++;

    // get value
    t = 0;
    while (s1[p1] != ',' && s1[p1] != '}') buff[t++] = s1[p1++];
    buff[t] = '\0';
    value = buff;
    p1++;
    dict1.push_back(P(key, value));

    //cout << key << " " << value << endl;
  }

  while (p2 < s2.size()) {
    int t;
    // get key
    t = 0;
    while (s2[p2] != ':') buff[t++] = s2[p2++];
    buff[t] = '\0';
    key = buff;
    p2++;

    // get value
    t = 0;
    while (s2[p2] != ',' && s2[p2] != '}') buff[t++] = s2[p2++];
    buff[t] = '\0';
    value = buff;
    p2++;
    dict2.push_back(P(key, value));

    //cout << key << " " << value << endl;
  }

  //trace();
}

void compare()
{
  for (int i = 0; i < dict2.size(); i++) {
    string key = dict2[i].first;
    string value = dict2[i].second;
    int found = 0, same = 0;
    for (int j = 0; j < dict1.size(); j++) {
      if (key == dict1[j].first) {
        if (value == dict1[j].second) same = 1;
        else same = 0;
        found = 1;
        break;
      }
    }

    if (found == 0) {
      inc.push_back(key);
    }
    else {
      if (same == 0) change.push_back(key);
    }
  }

  for (int i = 0; i < dict1.size(); i++) {
    string key = dict1[i].first;
    string value = dict1[i].second;

    int found = 0;
    for (int j = 0; j < dict1.size(); j++) {
      if (key == dict2[j].first) {
        found = 1;
        break;
      }
    }

    if (found == 0) del.push_back(key);
  }
}

void output()
{
  if (inc.size() == 0 && del.size() == 0 && change.size() == 0) {
    cout << "No changes\n\n";
    return;
  }

  for (int i = 0; i < inc.size(); i++) {
    if (i != 0) cout << ",";
    else cout << "+";
    cout << inc[i];

    if (i == inc.size()-1) cout << "\n";
  }



  for (int i = 0; i < del.size(); i++) {
    if (i != 0) cout << ",";
    else cout << "-";
    cout << del[i];
    if (i == del.size()-1) cout << "\n";
  }


  for (int i = 0; i < change.size(); i++) {
    if (i != 0) cout << ",";
    else cout << "*";
    cout << change[i];
    if (i == change.size()-1) cout << "\n";
  }

  cout << "\n";
}

int main()
{
  int rnd;
  cin >> rnd; getchar();
  for (int i = 0; i < rnd; i++) {
    input();
    //printf("compare...\n");
    compare();
    //printf("output...\n");
    output();
  }
}
