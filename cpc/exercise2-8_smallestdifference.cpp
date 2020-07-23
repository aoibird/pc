// POJ 2718
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int INF = 1000000000;
const int MAXN = 10+2;
vector<int> D;
int S[MAXN];
int N;

void print_set()
{
    for (int i = 0; i < D.size(); i++) printf("%d%c", D[i], i==D.size()-1?'\n':' ');
}

void input()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (isdigit(ch)) D.push_back(ch-'0');
        else ;
    }
}

void form(int x, int y, int n1, int n2, int &a, int &b)
{
    a = x;
    for (int i = 0, t = N-1; i < n1; t--) {
        if (D[t]!=x && D[t]!=y) { a *= 10; a += D[t]; i++; }
    }
    b = y;
    for (int i = 0, t = 0; i < n2; t++) {
        if (D[t]!=x && D[t]!=y) { b *= 10; b += D[t]; i++; }
    }
}

void solve()
{
    N = D.size(); // N >= 2
    sort(D.begin(), D.end());
    //print_set(); printf("N = %d\n------\n", N);
    int best = INF, besta, bestb;
    if (N % 2 == 0) {
        int a = 0, b = 0;
        for (int i = 0; i+1 < N; i++) {
            if (D[i] == 0 && i!=N-2) continue;
            form(D[i], D[i+1], (N-2)/2, (N-2)/2, a, b);
            int diff = (a > b) ? a - b : b - a;
            if (diff < best) { best = diff; besta = a; bestb = b; }
            //printf("(%d %d) a = %5d b = %5d\n", D[i], D[i+1], a, b);
        }
    }
    else {
        int a = 0, b = 0;
        int d1 = (D[0] == 0) ? D[1] : D[0];
        int d2 = D[N-1];
        form(d2, d1, (N-2)/2, (N-2)/2+1, a, b);
        int diff = (a > b) ? a - b: b - a;
        if (diff < best) { best = diff; besta = a; bestb = b; }
        //printf("(%d %d) a = %5d b = %5d\n", d1, d2, a, b);
    }
    //printf("\n\n");
    printf("%d\n", best);
}

int main()
{
    int TC; scanf("%d", &TC); getchar();
    for (int tc = 1; tc <= TC; tc++) {
        D.resize(0);
        input();
        solve();
    }
}
