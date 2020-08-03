// POJ 3104
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 100000+10;
int A[MAXN];
int N, K;
ll B[MAXN];

bool can(ll m)
{
    for (int i = 0; i < N; i++) { B[i] = A[i] - (m-1); }
    ll sum = 0;
    for (int i = 0; i < N; i++) if (B[i] > 0) sum += B[i];
    return (K-1)*m >= sum;
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]); }
        scanf("%d", &K);

        int lb = 0, ub = 2 * 1e9 + 10;
        while (lb < ub) {
            int mid = (lb+ub)/2;
            if (can(mid)) { ub = mid; }
            else { lb = mid+1; }
        }
        printf("%d\n", ub);
    }
}
