// POJ 2976
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

const double ERR = 0.00001;
const double INF = 1e9+10;
const int MAXN = 1000+10;
PII T[MAXN];
double S[MAXN];
int N, K;

bool can(double x)
{
    for (int i = 0; i < N; i++) S[i] = T[i].first - x * T[i].second;
    sort(S, S+N);

    double sum = 0;
    for (int i = 0; i < K; i++) sum += S[N-i-1];

    return sum >= 0;
}

int main()
{
    while (scanf("%d%d", &N, &K) == 2) {
        if (N == 0 && K == 0) break;

        for (int i = 0; i < N; i++) scanf("%d", &T[i].first);
        for (int i = 0; i < N; i++) scanf("%d", &T[i].second);
        K = N - K;

        double lb = 0, ub = INF;
        while ((ub-lb) > ERR) {
            double mid = (lb+ub)/2;
            if (can(mid)) { lb = mid; }
            else { ub = mid; }
        }
        printf("%.0lf\n", (100 * lb));
    }
}
