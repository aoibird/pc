// POJ 1981 Circle and Points
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
typedef pair<double,double> PDD;

const double PI2 = 3.141592653589793 / 2;
const double EPS = 1e-5;
const int MAXN = 300 + 5;
int N;
PDD A[MAXN]; // X, Y ~ [0.0, 10.0]
vector<PDD> C;

bool in(const PDD &c, const PDD &p)
{
    double d2 = (c.first-p.first)*(c.first-p.first) +
        (c.second-p.second)*(c.second-p.second);
    return (d2 - 1) < EPS;
}

void center(const PDD &a, const PDD &b)
{
    double l = sqrt((a.first-b.first)*(a.first-b.first)
                    + (a.second-b.second)*(a.second-b.second));
    if (l > 2) return;

    double t1 = (abs(b.first-a.first) < EPS) ?
        ((b.second-a.second > 0) ? PI2 : -PI2) :
        atan2((b.second-a.second), (b.first-a.first));
    double t2 = acos(l/2);
    double cy1 = sin(t1 + t2), cx1 = cos(t1 + t2);
    double cy2 = sin(t1 - t2), cx2 = cos(t1 - t2);

    C.push_back(PDD(a.first + cx1, a.second + cy1));
    if (abs(cx1 - cx2) < EPS && abs(cy1 - cy2) < EPS) return;
    else C.push_back(PDD(a.first + cx2, a.second + cy2));
}

int main()
{
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++) scanf("%lf%lf", &A[i].first, &A[i].second);
        C.clear();

        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                center(A[i], A[j]);
            }
        }

        // for (int i = 0, l = C.size(); i < l; i++) {
        //     printf("(%lf, %lf)%c", C[i].first, C[i].second,(i==l-1)?'\n':' ');
        // }

        int maxp = 1;
        for (int i = 0, l = C.size(); i < l; i++) {
            int p = 0;
            for (int j = 0; j < N; j++) {
                if (in(C[i], A[j])) p++;
            }
            maxp = max(maxp, p);
        }
        printf("%d\n", maxp);
    }
}
