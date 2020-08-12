// POJ 3684 Physics Experiment
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

const int MAXN = 100+10;
const double g = 10.0;
int N, H, R, T;
double P[MAXN];

double calc(int T)
{
    if (T < 0) return H;
    double t = sqrt(2 * H / g);
    int k = (int)(T / t);
    double d;
    if (k % 2 == 0) d = T - k*t;
    else d = k*t + t - T;
    return H-g*d*d/2;
}

int main()
{
    int TC; scanf("%d", &TC);
    while (scanf("%d%d%d%d", &N, &H, &R, &T) == 4) {
        for (int i = 0; i < N; i++) P[i] = calc(T-i);
        sort(P, P+N);
        for (int i = 0; i < N; i++) {
            printf("%.2f%c", P[i]+2*R*i/100.0, i+1==N?'\n':' ');
        }
    }
}
