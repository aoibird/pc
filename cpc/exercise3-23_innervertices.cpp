// POJ 3109 Inner Vertices
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

const int MAXN = 100000+5;
PII A[MAXN];
int X[MAXN], Y[MAXN];
int N, CX, CY;
int vertical[MAXN];
int vis[MAXN];

int sum(int *bit, int i)
{
    int s = 0; for ( ; i > 0; i-=i&-i) { s += bit[i]; } return s;
}

void add(int *bit, int n, int i, int x)
{
    for ( ; i <= n; i+=i&-i) bit[i] += x;
}

int compress(int *x, int N)
{
    vector<int> xs;
    for (int i = 0; i < N; i++) xs.push_back(x[i]);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < N; i++)
        x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin() + 1;
    return xs.size();
}

bool cmp(const PII &a, const PII &b)
{
    return (a.second<b.second)||(a.second==b.second&&a.first<b.first);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d%d", &X[i], &Y[i]);

        CX = compress(X, N);
        CY = compress(Y, N);

        for (int i = 0; i < N; i++) A[i] = PII(X[i], Y[i]);
        sort(A, A+N, cmp);
        sort(A, A+N);
        int cnt = N;
        memset(vertical, 0, sizeof(vertical));
        memset(vis, -1, sizeof(vis));
        for (int i = 0; i < N; i++) {
            if (i+1 < N && A[i+1].first == A[i].first
                && A[i+1].second-A[i].second-1 >= 1) {
                int l = A[i].second+1, r = A[i+1].second-1;
                add(vertical, CY, l, 1);
                add(vertical, CY, r+1, -1);
            }
            int curr = sum(vertical, A[i].second);
            if (vis[A[i].second] != -1) cnt += curr - vis[A[i].second];
            vis[A[i].second] = curr;
        }
        printf("%d\n", cnt);
    }
}
