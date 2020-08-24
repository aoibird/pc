#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

struct Card {
    int type, move;
    Card(int t=0, int m=0) { type=t; move=m; }
};

const int MAXN = 1000+10;
Card A[MAXN];
int N;

bool cmp(const Card &a, const Card &b)
{
    return (a.move > b.move) || (a.move==b.move && a.type<b.type);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) {
            int t, p, n; scanf("%d%d%d", &t, &p, &n);
            int neg = 0; if (p < 0) { neg = -p; p = 0; }
            int pos = 0; if (n < 0) { pos = -n; n = 0; }
            n += neg, p += pos;
            A[i] = Card(t, p-n);
            // printf("%d %d %d\n", t, p, n);
        }

        sort(A, A+N, cmp);
        int x = 1, y = 1; bool win = true;
        for (int i = 0; i < N; i++) {
            // printf("%d %d\n", A[i].type, A[i].move);
            if (A[i].type == 1) x += A[i].move;
            if (A[i].type == 2) y += A[i].move;
            if (x <= 0 || y <= 0) { win = false; break; }
        }
        if (win) printf("YES\n(%d, %d)\n", x, y);
        else printf("NO\n");
    }
}
