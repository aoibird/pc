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
PII A[MAXN], B[MAXN];
int X[MAXN], Y[MAXN];
int N, CX, CY;

// int BITX[MAXN], BITY[MAXN];

// int sum(int *bit, int i)
// {
//     int s = 0; for (; i > 0; i-=i&-i) { s += bit[i]; } return s;
// }

// void add(int *bit, int n, int i, int x)
// {
//     for ( ; i <= n; i-=i&-i) bit[i] += x;
// }

void compress(int *x, int N)
{
    vector<int> xs;
    for (int i = 0; i < N; i++) xs.push_back(x[i]);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < N; i++)
        x[i] = find(xs.begin(), xs.end(), x[i]) - xs.begin();
}


bool cmp(const PII &a, const PII &b)
{
    return (a.second<b.second)||(a.second==b.second&&a.first<b.first);
}

int get_count(int fy, int ty, int x)
{
    int cnt = 0;
    for (int i = fy+1; i <= ty-1; i++) {
        int p = lower_bound(B, B+N, PII(x, i), cmp)-B;
        // printf("i = %d p = %d (%d %d)\n", i, p, B[p].first, B[p].second);
        if (B[p].second == i && B[p].first > x
            && p-1 >= 0 && B[p-1].first < x) cnt++;
    }
    // printf("%d\n", cnt);
    return cnt;
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d%d", &X[i], &Y[i]);
        // memset(BITX, 0, sizeof(BITX));
        // memset(BITY, 0, sizeof(BITY));

        compress(X, N);
        compress(Y, N);

        for (int i = 0; i < N; i++) A[i] = B[i] = PII(X[i], Y[i]);
        sort(A, A+N);
        sort(B, B+N, cmp);
        // for (int i = 0; i < N; i++) {
        //     printf("(%d %d)%c", A[i].first, A[i].second, i+1==N?'\n':' ');
        // }
        // for (int i = 0; i < N; i++) {
        //     printf("(%d %d)%c", B[i].first, B[i].second, i+1==N?'\n':' ');
        // }
        int cnt = N;
        for (int i = 0, p = i; i < N; i = p) {
            while (A[i].first == A[p].first) p++;
            if (i == p-1) continue;
            // printf("[%d %d]: (%d %d) (%d %d)\n", i, p,
            //        A[i].first, A[i].second, A[p-1].first, A[p-1].second);
            int fy = A[i].second, ty = A[p-1].second, x = A[i].first;
            cnt += get_count(fy, ty, x);
        }
        printf("%d\n", cnt);
    }
}
