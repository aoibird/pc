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

const int MAXN = 1e5+10;
int A[MAXN];
int N, K;

void query(int q, int &s, int &f, int &t)
{
    int l = 0, r = 0, sum = 0;
    while (l < N && r < N) {
        while (r < N && abs(sum) < q) {
            sum += A[r++];
            if (abs(q-abs(sum)) < abs(q-s)) { f = l, t = r-1, s = abs(sum); }
        }

        sum -= A[l++];
    }
}

int main()
{
    while (scanf("%d%d", &N, &K) == 2) {
        if (N == 0 && K == 0) break;
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        for (int i = 0; i < K; i++) {
            int q; scanf("%d", &q);
            int s = 0, f = 0, t = 0;
            query(q, s, f, t);
            printf("%d %d %d\n", s, f+1, t+1);
        }
    }
}
