// POJ 2566
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

const int INF = 0x80808080;
const int MAXN = 1e5+10;
int A[MAXN];
PII S[MAXN];
int N, K;

void print_array(PII *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("(%d,%d)%c", a[i].first, a[i].second, i==n-1?'\n':' ');
}

void save_best(int q, int sum, int l, int r, int &s, int &f, int &t)
{
    if (abs(q-sum) < abs(q-s)) {
        f = min(S[l].second, S[r].second);
        t = max(S[l].second, S[r].second);
        s = sum;
    }
}


void query(int q, int &s, int &f, int &t)
{
    int l = 0, r = 0; int sum = INF; s = INF;
    while (true) {
        while (r < N && sum < q) {
            r++;
            if (l >= r) sum = INT_MIN;
            else {
                sum = S[r].first - S[l].first;
                save_best(q, sum, l, r, s, f, t);
            }
        }
        if (sum < q) break;

        l++;
        if (l >= r) {
            sum = INT_MIN;
        }
        else {
            sum = S[r].first - S[l].first;
            save_best(q, sum, l, r, s, f, t);
        }
    }
}

int main()
{
    while (scanf("%d%d", &N, &K) == 2) {
        if (N == 0 && K == 0) break;
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        S[0] = PII(0, 0);
        for (int i = 1; i <= N; i++) S[i] = PII(S[i-1].first + A[i-1], i);
        sort(S, S+N+1);
        // print_array(S, N+1);

        for (int i = 0; i < K; i++) {
            int q; scanf("%d", &q);
            int s = 0, f = 0, t = 0;
            query(q, s, f, t);
            printf("%d %d %d\n", s, f+1, t);
        }
    }
}
