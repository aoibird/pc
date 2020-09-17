// POJ 2187 Beauty Contest
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
typedef pair<int,int> PII;

const double EPS = 1e-10;
double add(double a, double b) { return (abs(a+b)<EPS*(abs(a)+abs(b))) ? 0 : a+b; }

struct Point {
    double x, y;
    Point(double xi=0, double yi=0) { x=xi; y=yi; }
    Point operator+(Point p) { return Point(add(x, p.x), add(y, p.y)); }
    Point operator-(Point p) { return Point(add(x, -p.x), add(y, -p.y)); }
    double dot(Point p) { return add(x * p.x, y * p.y); }
    double det(Point p) { return add(x * p.y, -y * p.x); }
};

const int MAXN = 50000+5;
int N;
Point PS[MAXN];

bool cmp(const Point &a, const Point &b)
{
    return a.x<b.x||(a.x==b.x && a.y<b.y);
}

double dist(Point a, Point b) { return (a - b).dot(a - b); }

vector<Point> convex_hull(Point *ps, int n)
{
    sort(ps, ps+n, cmp);
    int k = 0;
    vector<Point> qs(n * 2);
    for (int i = 0; i < n; i++) {
        while (k > 1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for (int i = n-2, t = k; i >= 0; i--) {
        while (k > t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);
    return qs;
}

void solve()
{
    vector<Point> qs = convex_hull(PS, N);
    double res = 0;
    for (int i = 0; i < qs.size(); i++) {
        for (int j = 0; j < i; j++) res = max(res, dist(qs[i], qs[j]));
    }
    printf("%.0f\n", res);
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%lf%lf", &PS[i].x, &PS[i].y);

        solve();
    }
}
