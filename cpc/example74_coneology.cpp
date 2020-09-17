// POJ 2932 Coneology
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<double,int> PDI;

const int MAXN = 40000+5;
int N;
double X[MAXN], Y[MAXN], R[MAXN];

bool inside(int i, int j)
{
    double dx = X[i]-X[j], dy = Y[i]-Y[j];
    return dx * dx + dy * dy <= R[i]*R[j];
}

void solve()
{
    vector<PDI> events;
    for (int i = 0; i < N; i++) {
        events.push_back(PDI(X[i]-R[i], i)); // id < N, left
        events.push_back(PDI(X[i]+R[i], i+N)); // id >= N, right
    }
    sort(events.begin(), events.end());

    set<PDI> outers;
    vector<int> res;
    for (int i = 0; i < events.size(); i++) {
        int id = events[i].second % N;
        if (events[i].second < N) {
            set<PDI>::iterator it = outers.lower_bound(PDI(Y[id], id));
            if (it != outers.end() && inside(id, it->second)) continue;
            if (it != outers.begin() && inside(id, (--it)->second)) continue;
            res.push_back(id);
            outers.insert(PDI(Y[id], id));
        }
        else {
            outers.erase(PDI(Y[id], id));
        }
    }
    sort(res.begin(), res.end());

    printf("%d\n", (int)res.size());
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i]+1, i+1==res.size()?'\n':' ');
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%lf%lf%lf", &R[i], &X[i], &Y[i]);

        solve();
    }
}
