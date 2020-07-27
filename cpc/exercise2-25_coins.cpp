// POJ 1742
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 100+10;
//const int MAXM = 1e5+10;
int A[MAXN];
int C[MAXN];
set<int> dp;
int N, M;

void print_array(bool a[MAXN], int n) {
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


void solve()
{
    dp.insert(0);
    for (int i = 0; i < N; i++) {
        int a = A[i], c = C[i];
        vector<int> t; t.resize(0);
        for (set<int>::iterator it = dp.begin(); it != dp.end(); it++) {
            for (int k = 1; k <= c && *it + a*k <= M; k++) t.push_back(*it + a*k);
        }
        for (int i = 0; i < t.size(); i++) dp.insert(t[i]);
    }
    // for (set<int>::iterator it = dp.begin(); it != dp.end(); it++) { printf("%d ", *it); }
    // printf("\n");
    printf("%d\n", (int)dp.size()-1);
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        if (N == 0 && M == 0) break;
        dp.clear();
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]); }
        for (int i = 0; i < N; i++) { scanf("%d", &C[i]); }
        solve();
    }
}
