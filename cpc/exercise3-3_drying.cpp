// POJ 3104
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

const int MAXN = 100000+10;
int A[MAXN];
int B[MAXN];
int N, K;

bool can(int m)
{
    priority_queue<PII> pq;
    for (int i = 0; i < N; i++) B[i] = A[i];
    for (int i = 0; i < N; i++) pq.push(PII(B[i], i));

    for (int i = 0; i < m && !pq.empty(); i++) {
        bool dry = false;
        while (!pq.empty()) {
            PII p = pq.top(); pq.pop();
            int water = p.first, index = p.second;
            if (!dry) { water -= K; dry = true; }
            else { water -= 1; }
            B[index] = water;
        }
        for (int j = 0; j < N; j++) if (B[j] > 0) pq.push(PII(B[j], j));
    }

    return pq.empty();
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        scanf("%d", &K);

        int lb = 0, ub = 2 * 1e9;
        while (lb < ub) {
            int mid = (lb+ub)/2;
            if (can(mid)) { ub = mid; }
            else { lb = mid+1; }
        }
        printf("%d\n", ub);
    }
}
