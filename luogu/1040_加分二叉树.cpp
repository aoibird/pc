// Luogu 1040 加分二叉树
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

const int MAXN = 30+5;
int A[MAXN];
int N;
int R[MAXN][MAXN];

ll dfs(int l, int r)
{
    if (l > r) return 1;
    else if (l == r) { R[l][r] = l; return A[l]; }

    ll m = 0;
    for (int i = l; i <= r; i++) {
        ll vl = dfs(l, i-1);
        ll vr = dfs(i+1, r);
        if (A[i] + vl * vr > m) {
            m = A[i] + vl * vr;
            R[l][r] = i;
        }
    }
    return m;
}

void print_solution(int l, int r)
{
    if (l > r) return;

    printf(" %d", R[l][r]+1);
    print_solution(l, R[l][r]-1);
    print_solution(R[l][r]+1, r);
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        ll m = dfs(0, N-1);
        printf("%lld\n", m);
        int l = 0, r = N-1;
        printf("%d", R[l][r]+1);
        print_solution(0, R[l][r]-1);
        print_solution(R[l][r]+1, N-1);
        printf("\n");
    }
}
