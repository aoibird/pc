#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#define MAXT 1005
using namespace std;

queue<int> qm[MAXT]; // member queue
queue<int> qt; // team queue
map<int, int> teamid;
int teams;

void init()
{
  for (int i = 0; i < teams; i++) {
    while (!qm[i].empty()) qm[i].pop();
  }
  while (!qt.empty()) qt.pop();
}

void input()
{
  int mems;
  int memid;
  for (int i = 0; i < teams; i++) {
    cin >> mems;
    //printf("%d:", i);
    for (int j = 0; j < mems; j++) {
      cin >> memid;
      teamid[memid] = i;
      //printf(" %d", memid);
    }
    //printf("\n");
  }
}

void output()
{

  while (!qt.empty()) {
    int t = qt.front(); qt.pop();
    while (!qm[t].empty()) {
      cout << qm[t].front() << endl;
      qm[t].pop();
    }
  }
}


int main()
{
  int cas = 1;
  while (scanf("%d", &teams) && teams) {
    printf("Scenario #%d\n", cas);

    init();
    input();

    string cmd;
    while (cin >> cmd) {
      //cout << cmd << endl;
      if (cmd == "STOP") break;

      if (cmd == "ENQUEUE") {
        int memid;
        cin >> memid;
        int t = teamid[memid];

        //cout << t << " " << memid << endl;
        if (qm[t].empty()) qt.push(t);
        qm[t].push(memid);
      }
      else if (cmd == "DEQUEUE") {
        int ft = qt.front();
        cout << qm[ft].front() << endl;
        qm[ft].pop();
        if (qm[ft].empty()) qt.pop();
      }
      else ;
    }
    printf("\n");

    //output();

    cas++;
  }
}
