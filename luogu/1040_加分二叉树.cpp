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

int dfs(int l, int r, vector<int> &v)
{
    if (l > r) return 1;
    else if (l == r) { v.push_back(l); return A[l]; }

    int m = 0;
    vector<int> sl, sr;
    for (int i = l; i <= r; i++) {
        int vl = dfs(l, i-1, sl);
        int vr = dfs(i+1, r, sr);
        if (A[i] + vl * vr > m) {
            m = A[i] + vl * vr;
            v.resize(0);
            v.push_back(i);
            for (int i = 0; i < sl.size(); i++) v.push_back(sl[i]);
            for (int i = 0; i < sr.size(); i++) v.push_back(sr[i]);
            sl.resize(0), sr.resize(0);
        }
    }
    return m;
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        vector<int> v;
        int m = dfs(0, N-1, v);
        printf("%d\n", m);
        for (int i = 0; i < v.size(); i++) printf("%d%c", v[i]+1, i+1==v.size()?'\n':' ');
    }
}
