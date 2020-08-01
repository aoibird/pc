// AOJ 2170
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

const int MAXN = 1e5 + 5;
int T[MAXN];
int N, Q;

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}

int dfs(int x)
{
    if (T[x] == x) return x;
    else return dfs(T[x]);
}

int main()
{
    while (scanf("%d%d", &N, &Q) == 2) {
        if (N == 0 && Q == 0) break;
        // printf("N == %d Q == %d\n", N, Q);
        T[1] = 1;
        for (int i = 2; i <= N; i++) {
            scanf("%d", &T[i]); getchar();
        }
        // print_array(par, N+1);

        string line; ll sum = 0;
        for (int i = 0; i < Q; i++) {
            getline(cin, line);
            if (line[0] == 'M') {
                int x; sscanf(line.c_str()+2, "%d", &x);
                T[x] = x;
            }
            else if (line[0] == 'Q') {
                int x; sscanf(line.c_str()+2, "%d", &x);
                sum += dfs(x);
            }
            else ;
        }
        printf("%lld\n", sum);
    }
}
