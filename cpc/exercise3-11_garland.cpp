// POJ 1579
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

int N;
double A;

double can(double x)
{
    double a = A, m = x, b;
    for (int i = 2; i < N; i++) {
        b = 2 * (m + 1) - a;
        a = m; m = b;
        if (b < 0) break;
    }
    return b;
}

int main()
{
    while (scanf("%d%lf", &N, &A) == 2) {
        double lb = -1, ub = 1000+10;
        for (int i = 0; i < 100; i++) {
            double mid = (lb+ub)/2;
            if (can(mid) >= 0) ub = mid;
            else lb = mid;
        }
        printf("%.2lf\n", can(ub));
    }
}
