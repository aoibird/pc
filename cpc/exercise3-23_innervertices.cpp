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

// const int INF = 1e9 + 10;
const int MAXN = 100000+5;
PII A[MAXN];
int X[MAXN], Y[MAXN];
int N, CX, CY;
int vertical[MAXN];
PII RX[MAXN];

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

void get_range(PII *array, int N)
{
    for (int i = 0, p = 0; i < N; i = p) {
        while (p < N && array[i].second == array[p].second) p++;
        if (p-1 == i) continue;
        RX[array[i].second] = PII(array[i].first, array[p-1].first);
    }
}


int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d%d", &X[i], &Y[i]);

        CX = compress(X, N);
        CY = compress(Y, N);

        for (int i = 0; i < N; i++) A[i] = PII(X[i], Y[i]);
        sort(A, A+N, cmp);
        get_range(A, N);
        sort(A, A+N);
        // for (int i = 0; i < N; i++) printf("(%d %d) ", A[i].first, A[i].second); printf("\n");
        int cnt = N;
        memset(vertical, 0, sizeof(vertical));
        for (int i = 0; i < N; i++) {
            // printf("(%d %d)\n", A[i].first, A[i].second);
            // printf("(%d %d)\n", A[i].first, A[i].second);
            if (i+1 < N && A[i+1].first == A[i].first
                && A[i+1].second-A[i].second-1 >= 1) {
                int l = A[i].second+1, r = A[i+1].second-1;
                // printf("  Add [%d %d] + %d\n", l, r, 1);
                add(vertical, CY, l, 1);
                add(vertical, CY, r+1, -1);
            }
            if (A[i].first == RX[A[i].second].first) {
                int l = A[i].second, r = A[i].second;
                int t = sum(vertical, l);
                // printf("  Sub [%d %d] - %d\n", l, r, t);
                add(vertical, CY, l, -t);
                add(vertical, CY, r+1, t);
            }
            if (A[i].first == RX[A[i].second].second) {
                int l = A[i].second;
                int t = sum(vertical, l);
                // printf("  Count [%d %d] %d\n", l, l, t);
                cnt += t;
            }
            // for (int i = 0; i < CY; i++) printf("%d%c", vertical[i], i+1==CY?'\n':' ');
        }
        printf("%d\n", cnt);
    }
}
