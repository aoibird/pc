// POJ 3579
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

const int MAXN = 100000+10;
int A[MAXN];
ll N, M;

bool can(ll x)
{
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        ll target = A[i] + x;
        cnt += (A + N) - lower_bound(A, A+N, target);
    }
    return cnt <= M/2;
}

int main()
{
    while (scanf("%lld", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        sort(A, A+N);
        M = N * (N - 1) / 2;
        ll lb = 0, ub = A[N-1] - A[0] + 10;
        while (ub - lb > 1) {
            ll mid = lb+(ub-lb)/2;
            if (can(mid)) ub = mid;
            else lb = mid;
        }
        printf("%lld\n", lb);
    }
}
