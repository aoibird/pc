// POJ 2010
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
typedef long long ll;
typedef pair<int,int> PII;

struct Calf {
    int index, score, aid;
    Calf(int i=0, int s=0, int a=0) { index=i; score=s; aid=a; }
};

// const int INF = 0x3f3f3f3f;
const int INF = 2 * 1e9 + 10;
const int MAXC = 1e5+10;
PII A[MAXC]; // (score, finanicial aid) score_i < score_j
int back[MAXC];
int front[MAXC];
int N, C, F;
priority_queue<int> Q;

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


void solve()
{
    sort(A, A+C);

    int sum;
    sum = 0;
    while (!Q.empty()) Q.pop();
    for (int i = 0; i < C; i++) {
        back[i] = (Q.size()==N/2) ? sum : INF;
        Q.push(A[i].second);
        sum += A[i].second;
        if (Q.size() > N/2) { sum -= Q.top(); Q.pop(); }
    }
    while (!Q.empty()) Q.pop();
    sum = 0;
    for (int i = C-1; i >= 0; i--) {
        front[i] = (Q.size()==N/2) ? sum : INF;
        Q.push(A[i].second);
        sum += A[i].second;
        if (Q.size() > N/2) { sum -= Q.top(); Q.pop(); }
    }

    // print_array(back, C);
    // print_array(front, C);

    for (int i = C-1; i >= 0; i--) {
        if (back[i] + front[i] + A[i].second <= F) {
            printf("%d\n", A[i].first); return;
        }
    }
    printf("-1\n");
}

int main()
{
    while (scanf("%d%d%d", &N, &C, &F) == 3) {
        for (int i = 0; i < C; i++) {
            int s, a; scanf("%d%d", &s, &a);
            A[i] = PII(s, a);
        }
        solve();
    }
}
