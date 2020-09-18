// POJ 3168 Barn Expansion
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

// const int INF = 1000000+5;
const int MAXN = 25000+5;
int N;
struct Barn {
    int x1, y1, x2, y2; bool expand;
    Barn(int a=0, int b=0, int c=0, int d=0) { x1=a; y1=b; x2=c; y2=d; expand=true; }
};
Barn A[MAXN];

void print_barn()
{
    for (int i = 0; i < N; i++)
        printf("%d %d %d %d\n", A[i].x1, A[i].x2, A[i].y1, A[i].y2);
}

bool cmp_x(const Barn &a, const Barn &b)
{
    if (a.x1 != b.x1) return a.x1 < b.x1;
    else if (a.x2 != b.x2) return a.x2 < b.x2;
    else if (a.y1 != b.y1) return a.y1 < b.y1;
    else if (a.y2 != b.y2) return a.y2 < b.y2;
    else return false;
}

bool cmp_y(const Barn &a, const Barn &b)
{
    if (a.y1 != b.y1) return a.y1 < b.y1;
    else if (a.y2 != b.y2) return a.y2 < b.y2;
    else if (a.x1 != b.x1) return a.x1 < b.x1;
    else if (a.x2 != b.x2) return a.x2 < b.x2;
    else return false;
}

void solve()
{
    sort(A, A+N, cmp_x);
    // print_barn(); printf("\n");
    for (int i = 0; i < N; i++) {
        int x = A[i].x2;
        int expand = true;
        for (int j = i+1; j < N && A[j].x1 == x; j++) {
            if (A[j].x1 == x && !(A[j].y1 > A[i].y2 || A[j].y2 < A[i].y1)) {
                A[j].expand = false; expand = false;
            }
        }
        if (expand == false) A[i].expand = expand;
        // printf("%d %d %d %d: %d (%d)\n",
        //        A[i].x1, A[i].x2, A[i].y1, A[i].y2, x, A[i].expand);
    }

    sort(A, A+N, cmp_y);
    // print_barn(); printf("\n");
    for (int i = 0; i < N; i++) {
        int y = A[i].y2;
        int expand = true;
        for (int j = i+1; j < N && A[j].y1 == y; j++) {
            if (A[j].y1 == y && !(A[j].x1 > A[i].x2 || A[j].x2 < A[i].x1)) {
                A[j].expand = false; expand = false;
            }
        }
        if (expand == false) A[i].expand = expand;
        // printf("%d %d %d %d: %d (%d)\n",
        //        A[i].x1, A[i].x2, A[i].y1, A[i].y2, y, A[i].expand);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i].expand == true) cnt++;
    }

    printf("%d\n", cnt);
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) {
            int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
            A[i] = Barn(a, b, c, d);
        }

        solve();
    }
}
