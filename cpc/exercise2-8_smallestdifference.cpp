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
    // print_set();
}

int difference(int s1, int l1, int s2, int l2)
{
    if (D[s1] == 0 && l1 > 1) return INF;
    if (D[s2] == 0 && l2 > 1) return INF;
    char buf[100]; int v1, v2;
    for (int i = 0; i < l1; i++) { buf[i] = D[s1+i]+'0'; } buf[s1+l1] = '\0';
    v1 = atoi(buf);
    for (int i = 0; i < l2; i++) { buf[i] = D[s2+i]+'0'; } buf[s2+l2] = '\0';
    v2 = atoi(buf);
    return abs(v1 - v2);
}

void solve()
{
    N = D.size();
    int best = INF;
    do {
        // print_set();
        if (N % 2 == 0) {
            best = min(best, difference(0, N/2, N/2, N/2));
        }
        else {
            best = min(best, difference(0, N/2, N/2, N/2));
            best = min(best, difference(0, N/2+1, N/2+1, N/2-1));
        }
    } while (next_permutation(D.begin(), D.end()));
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
