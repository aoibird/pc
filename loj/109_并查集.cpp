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


const int MAXN = 4000000+10;
int par[MAXN];
int N, M;

void init() { for (int i = 0; i < N; i++) par[i] = i; }

int find(int x) { if (par[x] == x) return x; else return par[x] = find(par[x]); }

void merge(int x, int y) { x = find(x); y = find(y); if (x == y) return; else par[y] = x; }

bool same(int x, int y) { return find(x) == find(y); }

int main()
{
    scanf("%d%d", &N, &M);
    init();
    int res = 0;
    for (int i = 0; i < M; i++) {
        int op, u, v;
        scanf("%d%d%d", &op, &u, &v);
        if (op == 0) {
            merge(u, v);
        } else if (op == 1) {
            int r = same(u, v);
            res <<= 1;
            res += r;
            res = res % 998244353;
        }
    }
    printf("%d\n", res);
}
