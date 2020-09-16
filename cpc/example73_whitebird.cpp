// AOJ 2308 White Bird
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

const double EPS = 1e-10;
const double g = 9.8;
const int MAXN = 50+5;
int N, V, X, Y;
int L[MAXN], B[MAXN], R[MAXN], T[MAXN];

double calc(double vy, double t) { return vy*t - g*t*t/2; }
int cmp(double lb, double ub, double a) { return (a<lb+EPS) ? -1 : (a>ub-EPS) ? 1 : 0; }
bool check(double qx, double qy)
{
    // (vx^2 + vy^2 = v^2), (vx * t = qx), (vy * t - 1/2 * g * t^2 = qy)
    double a = g*g/4, b = g*qy-V*V, c = qx*qx+qy*qy, delta = b*b - 4*a*c;
    if (-EPS < delta && delta < 0) delta = 0;
    if (delta < 0) return false;

    for (int sign = -1; sign <= 1; sign += 2) { // (-b +- sqrt(delta)) / 2a
        double t2 = (-b + sign * sqrt(delta)) / (2*a);
        if (t2 <= 0) continue;
        double t = sqrt(t2);
        double vx = qx / t, vy = (qy + g*t*t/2) / t;

        double yt = calc(vy, X / vx);
        if (yt < Y - EPS) continue;

        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (L[i] >= X) continue;
            if (R[i] == X && Y <= T[i] && B[i] <= yt) continue;
            int yL = cmp(B[i], T[i], calc(vy, L[i]/vx));
            int yR = cmp(B[i], T[i], calc(vy, R[i]/vx));
            int xH = cmp(L[i], R[i], vx * (vy/g));
            int yH = cmp(B[i], T[i], calc(vy, vy/g));
            if (xH == 0 && yH >= 0 && yL < 0) ok = false;
            if (yL * yR <= 0) ok = false;
        }
        if (ok) return true;
    }
    return false;
}

void solve()
{
    for (int i = 0; i < N; i++) R[i] = min(R[i], X);
    bool ok = check(X, Y);
    for (int i = 0; i < N; i++) {
        ok |= check(L[i], T[i]);
        ok |= check(R[i], T[i]);
    }

    if (ok) printf("Yes\n");
    else printf("No\n");
}

int main()
{
    while (scanf("%d%d%d%d", &N, &V, &X, &Y) == 4) {
        for (int i = 0; i < N; i++)
            scanf("%d%d%d%d", &L[i], &B[i], &R[i], &T[i]);

        solve();
    }
}
