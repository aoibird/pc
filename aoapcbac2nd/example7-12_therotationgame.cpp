// UVa 1343
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 800000;
const int N = 24;     // blocks
const int K = 8;      // kinds of directions, count of pieces
const int L = 3;      // kinds of blocks symbol 1, 2, 3
int init_state[N];
int curr_state[N];     // current state
vector<int> currpath; // current
vector<int> bestpath; // best
int best;             // best moves
int bestk;            // best kind
int visited[1 << N]; // 24 bits 01-string 2^24
// 24! / (8! * 16!) = 735471
int pre[1 << N];
int op[1 << N];

int center[K] = {6, 7, 8, 11, 12, 15, 16, 17};
int lines[K][7] = {{0, 2, 6, 11, 15, 20, 22}, // A
                   {1, 3, 8, 12, 17, 21, 23}, // B
                   {10, 9, 8, 7, 6, 5, 4}, // C
                   {19, 18, 17, 16, 15, 14, 13}, // D
                   {23, 21, 17, 12, 8, 3, 1}, // E
                   {22, 20, 15, 11, 6, 2, 0}, // F
                   {13, 14, 15, 16, 17, 18, 19}, // G
                   {4, 5, 6, 7, 8, 9, 10} // H
};
int letters[K] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

void trace();

void move(int d)
{
  int valh = curr_state[lines[d][0]];
  int p;
  for (p = 0; p < 6; p++) {
    int pos = lines[d][p];
    int posb = lines[d][p+1];
    curr_state[pos] = curr_state[posb];
  }
  curr_state[lines[d][6]] = valh;

  //trace();
}

int match()
{
  for (int i = 0; i < K; i++) {
    if (curr_state[center[i]] != 1) return 0;
  }

  return 1;
}

int encode()
{
  int sum = 0;
  for (int i = 0, w = 1; i < N; i++, w *= 2) {
    sum += (w * curr_state[i]);
  }
  return sum;

}

void decode(int code)
{
  for (int i = 0, s = code; i < N; i++, s = s >> 1) {
    int b = s&1;
    curr_state[i] = b;
  }
}

void trace()
{
  for (int i = 0; i < N; i++) printf("%d ", curr_state[i]);
  printf(" %d %d\n", encode(), visited[encode()]);
}


void bfs(int k)
{
  queue<int> q, s;

  int start = encode();
  q.push(start);
  s.push(0);
  pre[start] = -1;
  op[start] = 0;
  visited[start] += 1; // why????

  //int cnt = 0;
  while (!q.empty()) {
    int curr = q.front(); q.pop();
    int step = s.front(); s.pop();

    //if (step >= 3) break;
    decode(curr);

    // debug
    // printf("%d\n", cnt++);


    // printf("%10d(%d) <-%c %10d ", curr, step, letters[op[curr]], pre[curr]);
    // for (int i = 0; i < N; i++) {
    //   if (i % 6 == 0) printf(" ");
    //   printf("%d", curr_state[i]);
    // }
    // printf("\n");
    //trace();

    //if (step > 7) break;
    if (step > best) break;

    if (match()) {
      // if the state satisfies the condition
      if (step < best) {
        bestpath.resize(0);
        best = step;
        bestk = k;
        int i = curr;
        while (pre[i] > 0) {
          bestpath.push_back(op[i]);
          i = pre[i];
        }
      }
      break;
    }

    // move for each directions
    for (int i = 0; i < K; i++) {
      //printf("move %d\n", i);
      move(i); // move
      int next = encode();
      if (visited[next] == 0) {
        //trace();
        q.push(next);
        s.push(step+1);
        pre[next] = curr;
        op[next] = i;
        visited[next] += 1; // why???
      }
      //move(K-i); // put back
      decode(curr);
    }

  }
  // printf("\n");

  // int cnt = 0;
  // for (int i = 0; i < (1 << N); i++) {
  //   if (visited[i] > 1) {
  //     cnt++;
  //     //printf("%d\n", i);
  //   }
  // }
  // printf("%d\n", cnt);
}


int main()
{
  int h;
  while (scanf("%d", &h) == 1 && h) {
    // input and init
    init_state[0] = h;
    for (int i = 1; i < N; i++) {
      scanf("%d", init_state+i);
    }
    best = INF;
    currpath.resize(0);
    bestpath.resize(0);


    // for each kinds of blocks
    for (int k = 1; k <= L; k++) {
      memset(visited, 0, sizeof(visited));
      for (int i = 0; i < N; i++) {
        if (init_state[i] == k) curr_state[i] = 1;
        else curr_state[i] = 0;
      }
      //printf("k = %d\n", k);
      //trace();
      bfs(k); // traversal
    }

    // print the path and kind
    for (int i = bestpath.size()-1; i >= 0; i--)
      printf("%c", letters[bestpath[i]]);
    printf("\n%d\n", bestk);
  }
}
