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

const int MAXN = 1e5;
int T[MAXN];
vector<int> CH[MAXN]; // children
int N, Q;

int par[MAXN];

void init(int n)
{
    for (int i = 1; i <= n; i++) par[i] = 1;
}

int find(int x)
{
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x); y = find(y);
    if (x == y) return;
    else par[y] = x;
}

void merge_subtree(int x)
{
    if (CH[x].size() == 0) return;

    for (int i = 0; i < CH[x].size(); i++) {
        unite(x, CH[x][i]);
        merge_subtree(CH[x][i]);
    }
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


int main()
{
    while (scanf("%d%d", &N, &Q) == 2) {
        if (N == 0 && Q == 0) break;
        for (int i = 1; i <= N; i++) CH[i].resize(0);
        init(N);

        T[1] = 1;
        for (int i = 2; i <= N; i++) {
            scanf("%d", &T[i]); getchar();
            CH[T[i]].push_back(i);
        }
        // print_array(par, N+1);


        string line; ll sum = 0;
        for (int i = 0; i < Q; i++) {
            getline(cin, line);
            if (line[0] == 'M') {
                int x; sscanf(line.c_str()+2, "%d", &x);
                // printf("Mark %d\n", x);
                par[x] = x;
                merge_subtree(x);
                // print_array(par, N+1);
            }
            else if (line[0] == 'Q') {
                int x; sscanf(line.c_str()+2, "%d", &x);
                // printf("Query %d\n", x);
                sum += find(x);
            }
            else ;
        }
        printf("%lld\n", sum);
    }
}
