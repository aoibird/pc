// POJ 1962 Corporative Network
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

const int MAXN = 20000+5;
int par[MAXN], dist[MAXN];
int N;

void init(int N)
{
    for (int i = 1; i <= N; i++) par[i] = i, dist[i] = 0;
}

int find(int x)
{
    if (par[x] == x) return x;
    else { int a = find(par[x]); dist[x] += dist[par[x]]; return par[x] = a; }
}

void unite(int u, int p)
{
    par[u] = p, dist[u] = abs(u-p) % 1000;
}

int main()
{
    int TC; scanf("%d", &TC);
    while (scanf("%d", &N) == 1) {
        init(N);
        char instr[10];
        while (scanf("%s", instr) == 1 && instr[0] != 'O') {
            if (instr[0] == 'E') {
                int u; scanf("%d", &u); find(u);
                printf("%d\n", dist[u] % 1000);
            }
            else if (instr[0] == 'I') {
                int u, p; scanf("%d%d", &u, &p); unite(u, p);
            }
            else ;
        }
    }
}
