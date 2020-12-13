// Codeforces 102460 K Length of Bundle Rope
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// const int MAXN = 1000+10;
priority_queue<int, vector<int>, greater<int> > pq;
int n;

void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        pq.push(a);
    }
}

void solve()
{
    int sum = 0;
    while (pq.size() > 1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        sum += (x + y);
        pq.push(x + y);
    }
    // printf("%d\n", sum);
    // sum += pq.top(); pq.pop();
    printf("%d\n", sum);
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        while (!pq.empty()) pq.pop();
        input();
        solve();
    }
}
