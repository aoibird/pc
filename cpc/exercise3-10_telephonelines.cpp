// POJ 3662
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 1000+5;
const int MAXL = 1000000+5;
int N, P, K;
vector<PII> G[MAXN];
int D[MAXN];

int dijkstra(int s, int lim)
{
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    memset(D, 0x3f, sizeof(D));
    D[s] = 0; pq.push(PII(D[s], s));
    while (!pq.empty()) {
        PII p = pq.top(); pq.pop();
        int v = p.second;
        if (D[v] < p.first) continue;
        for (int i = 0; i < G[v].size(); i++) {
            PII e = G[v][i]; int to = e.first, cost = (e.second >= lim);
            if (D[to] > D[v] + cost) {
                D[to] = D[v] + cost;
                pq.push(PII(D[to], to));
            }
        }
    }
    return D[N];
}


int main()
{
    while (scanf("%d%d%d", &N, &P, &K) == 3) {
        // printf("N, P, K = %d %d %d\n", N, P, K);
        for (int i = 0; i < MAXN; i++) G[i].clear();
        for (int i = 0; i < P; i++) {
            int a, b, l; scanf("%d%d%d", &a, &b, &l);
            G[a].push_back(PII(b, l));
            G[b].push_back(PII(a, l));
        }

        int lb = 0, ub = MAXL+5;
        while (ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if (dijkstra(1, mid) > K) lb = mid;
            else ub = mid;
        }

        printf("%d\n", (lb >= MAXL ? -1 : lb));
    }
}
