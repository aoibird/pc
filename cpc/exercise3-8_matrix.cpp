// POJ 3685
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

const ll INF = 25000000001LL;
ll N, M;

bool can(ll key)
{
    ll cnt = 0;
    for (ll i = 1; i <= N; i++) {
        ll lb = 0, ub = N+1, m;
        while (ub - lb > 1) {
            m = (ub+lb)/2;
            if (i*i + m*m + 100000*(m-i) + m*i <= key) { lb = m; }
            else { ub = m; }
        }
        cnt += lb;
    }
    if (cnt >= M) return true;
    return false;
}

void solve()
{
    ll lb = -INF, ub = INF, mid;
    while (ub - lb > 1) {
        mid = lb+(ub-lb)/2;
        // printf("%lld %lld %lld\n", lb, ub, mid);
        if (can(mid)) { ub = mid; }
        else { lb = mid; }
    }
    printf("%lld\n", ub);
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        scanf("%lld%lld", &N, &M);
        solve();
    }
}
