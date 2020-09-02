// POJ 1127 Jack Straws
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
double add(double a, double b) { return (abs(a+b)<EPS*(abs(a)+abs(b))) ? 0 : a+b; }

struct Point {
    double x, y;
    Point(double xi=0, double yi=0) { x=xi; y=yi; }
    Point operator+(Point p) { return Point(add(x, p.x), add(y, p.y)); }
    Point operator-(Point p) { return Point(add(x, -p.x), add(y, -p.y)); }
    Point operator*(double d) { return Point(x * d, y * d); }
    double dot(Point p) { return add(x*p.x, y*p.y);  }
    double det(Point p) { return add(x*p.y, -y*p.x); }
};

bool on_seg(Point p1, Point p2, Point q)
{
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

Point intersection(Point p1, Point p2, Point q1, Point q2)
{
    return p1 + (p2 - p1) * ((q2-q1).det(q1-p1) / (q2-q1).det(p2-p1));
}

const int MAXN = 13+2;
const int MAXM = 1e5+2;
int N, M;
Point p[MAXN], q[MAXN];
int a[MAXM], b[MAXM];
bool g[MAXN][MAXN];


void solve()
{
    memset(g, 0, sizeof(g));
    for (int i = 0; i < N; i++) {
        g[i][i] = true;
        for (int j = 0; j < i; j++) {
            if ((p[i] - q[i]).det(p[j] - q[j]) == 0) {
                g[i][j] = g[j][i] = on_seg(p[i], q[i], p[j])
                    || on_seg(p[i], q[i], q[j])
                    || on_seg(p[j], q[j], p[i]) || on_seg(p[j], q[j], q[i]);
            }
            else {
                Point r = intersection(p[i], q[i], p[j], q[j]);
                g[i][j] = g[j][i] = on_seg(p[i], q[i], r) && on_seg(p[j], q[j], r);
            }
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (g[a[i]][b[i]]) printf("CONNECTED\n");
        else printf("NOT CONNECTED\n");
    }
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) {
            int x, y, z, w; scanf("%d%d%d%d", &x, &y, &z, &w);
            p[i] = Point(x, y); q[i] = Point(z, w);
        }
        int ai, bi; M = 0;
        while (scanf("%d%d", &ai, &bi) == 2 && !(ai == 0 && bi == 0)) {
            ai--; bi--; a[M] = ai; b[M] = bi; M++;
        }

        solve();
    }
}
