#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <map>
#include <deque>
#define MAXN 105
#define MAXS 105
#define MAXC 20
using namespace std;

typedef pair<int, int> P;
char progs[MAXN][MAXS][MAXC];
int takes[5];
int N, t1, t2, t3, t4, t5, Q;
deque<P> ready;
queue<P> block;
map<string, int> vars;
int islock;

void trace()
{
  for (int i = 0; i < N; i++) {
    printf("%d:--\n", i);
    for (int j = 0; ; j++) {
      printf("%s\n", progs[i][j]);

      if (progs[i][j][0] == 'e' && progs[i][j][1] == 'n'&&
          progs[i][j][2] == 'd') {
        break;
      }
    }
  }

  printf("\n");
}

void input()
{
  scanf("%d", &N);
  for (int i = 0; i < 5; i++) scanf("%d", &takes[i]);
  scanf("%d", &Q);
  getchar();

  for (int i = 0; i < N; i++) {
    for (int j = 0; ; j++) {
      int c, p = 0;
      while ((c = getchar()) != '\n') progs[i][j][p++] = (char)c;
      progs[i][j][p] = '\0';
      if (progs[i][j][0] == 'e' && progs[i][j][1] == 'n' &&
          progs[i][j][2] == 'd') break;
    }
    ready.push_back(P(i, 0));
  }
}

int classify(int i, int j)
{
  // a = 4 : 0, print a : 1, lock : 2, unlock : 3, end : 4
  if (strstr(progs[i][j], "=")) return 0;
  else if (strstr(progs[i][j], "print")) return 1;
  else if (strstr(progs[i][j], "unlock")) return 3;
  else if (strstr(progs[i][j], "lock")) return 2;
  else if (strstr(progs[i][j], "end")) return 4;
  else return -1;
}


int main()
{
  input();
  //trace();

  islock = 0;
  while (!ready.empty()) {
    P prog = ready.front(); ready.pop_front();
    int number = prog.first;
    int stat = prog.second;
    int rest = Q;
    int type;


    while (rest != 0) {
      type = classify(number, stat);
      int take = takes[type];
      //printf("take: %d type: %d (%d, %d)\n", take, type, number, stat);
      //printf("%s\n", progs[number][stat]);

      if (type == 0) { // assignment

        char buff[MAXC];
        buff[0] = progs[number][stat][0]; buff[1] = '\0';
        string var = buff;
        char *p = progs[number][stat];
        while (!isdigit(*p)) p++;
        int i = 0;
        while (*p != '\0') buff[i++] = *p++;
        buff[i] = '\0';
        vars[var] = atoi(buff);

        //cout << var << " = " << atoi(buff) << endl;

        stat++;
      }
      else if (type == 1) { // print
        char buff[MAXC];
        buff[0] = progs[number][stat][6]; buff[1] = '\0';
        string var = buff;
        int con = vars[var];
        //cout << var << ": " << con << endl;
        printf("%d: %d\n", number+1, con);

        stat++;
      }
      else if (type == 2) { // lock
        if (islock) {
          //printf("push block: (%d, %d)\n", number, stat);
          block.push(P(number, stat));
          break;
        }
        else {
          islock = 1;
          stat++;
          ready.push_back(P(number, stat));
        }
      }
      else if (type == 3) { // unlock
        if (block.empty()) {
          stat++;
        }
        else {
          islock = 0;
          ready.push_front(P(number, stat+1));
          P b = block.front(); block.pop();
          int x = b.first;
          int y = b.second;
          ready.push_front(P(x, y));
          break;
        }
      }
      else if (type == 4) { // end
        break;
      }
      else {
        break;
      }

      rest -= take;
    }

    if (type == 0 || type == 1) ready.push_back(P(number, stat));
    else if (type == 3 && islock) ready.push_back(P(number, stat));
    else ;
  }

}
