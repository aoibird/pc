// POJ 3045
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

const int INF = 1e9;
const int MAXN = 50000+10;
PII C[MAXN];
int N;

bool cmp(const PII &a, const PII &b)
{
    return a.first + a.second < b.first + b.second;
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) scanf("%d%d", &C[i].first, &C[i].second);

        sort(C, C+N, cmp);

        int m = -INF, sum = 0;
        for (int i = 0; i < N; i++) {
            m = max(m, sum - C[i].second);
            sum += C[i].first;
        }
        printf("%d\n", m);
    }
}
