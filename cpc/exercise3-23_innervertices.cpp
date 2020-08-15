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
PII RX[MAXN]; // RX: Y1==Y2, X1<=X2
int N, CX, CY;

int compress(int *x, int N)
{
    vector<int> xs;
    for (int i = 0; i < N; i++) xs.push_back(x[i]);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < N; i++)
        x[i] = find(xs.begin(), xs.end(), x[i]) - xs.begin();
    return xs.size();
}

bool cmp(const PII &a, const PII &b)
{
    return (a.second<b.second)||(a.second==b.second&&a.first<b.first);
}

void get_range()
{
    for (int i = 0, p = 0; i < N; i = p) {
        while (p < N && B[i].second == B[p].second) p++;
        RX[B[i].second] = PII(B[i].first, B[p-1].first);
    }
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d%d", &X[i], &Y[i]);

        CX = compress(X, N);
        CY = compress(Y, N);

        for (int i = 0; i < N; i++) A[i] = B[i] = PII(X[i], Y[i]);
        sort(A, A+N);
        sort(B, B+N, cmp);
        get_range();
        int cnt = N;
        for (int i = 0, p = i; i < N; i = p) {
            while (A[i].first == A[p].first) p++;
            if (i == p-1) continue;
            // printf("[%d %d]: (%d %d) (%d %d)\n", i, p,
            //        A[i].first, A[i].second, A[p-1].first, A[p-1].second);
            int fy = A[i].second, ty = A[p-1].second, x = A[i].first;
            for (int j = fy; j <= ty; j++) {
                if (find(A, A+N, PII(x, j))-A != N) continue;
                if (RX[j].first < x && x < RX[j].second) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
