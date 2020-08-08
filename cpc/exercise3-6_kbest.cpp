// POJ 3111
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
typedef pair<double,int> PDI;

const int MAXN = 100000+10;
PII A[MAXN];
PDI S[MAXN];
int N, K;

bool can(double x)
{
    for (int i = 0; i < N; i++) {
        S[i].first = A[i].first - x*A[i].second;
        S[i].second = i;
    }
    sort(S, S+N);
    double sum = 0;
    for (int i = 0; i < K; i++) sum += S[N-i-1].first;
    return sum >= 0;
}

int main()
{
    while (scanf("%d%d", &N, &K) == 2) {
        for (int i = 0; i < N; i++) scanf("%d%d", &A[i].first, &A[i].second);

        double lb = 0, ub = 1e7 + 10;
        for (int i = 0; i < 100; i++) {
            double mid = lb + (ub-lb)/2;
            if (can(mid)) lb = mid;
            else ub = mid;
        }
        for (int i = 0; i < K; i++) printf("%d%c", S[N-i-1].second+1, i==K-1?'\n':' ');
    }
}
