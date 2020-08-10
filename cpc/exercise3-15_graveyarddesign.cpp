// POJ 2100
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
typedef pair<ll,ll> PLL;

vector<PLL> V;
ll N;

bool cmp(const PLL &a, const PLL &b)
{
    return a.second-a.first > b.second-b.first;
}

int main()
{
    while (scanf("%lld", &N) == 1) {
        ll l = 0, r = 0, sum = 0;
        V.resize(0);
        while (true) {
            while (r*r < N && sum < N) { sum += r*r; r++; }
            if (sum < N) break;

            if (sum == N) V.push_back(PLL(l, r));
            sum -= l*l; l++;
        }
        if (r * r == N) V.push_back(PLL(r, r+1));
        printf("%ld\n", V.size());
        sort(V.begin(), V.end(), cmp);
        for (int i = 0; i < V.size(); i++) {
            ll l = V[i].first, r = V[i].second;
            printf("%lld", r-l);
            for (ll i = l; i < r; i++) printf(" %lld", i);
            printf("\n");
        }
    }
}
