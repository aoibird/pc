// POJ 3262
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

const int MAXN = 100000 + 10;
PII A[MAXN];
ll S[MAXN];
int N;

bool cmp(const PII &a, const PII &b)
{
    return (a.first < b.first) || (a.first==b.first && a.second > b.second);
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) { int a, b; scanf("%d%d", &a, &b); A[i]=PII(a, b); }
        sort(A, A+N, cmp);

        S[N-1] = 0;
        for (int i = N-2; i >= 0; i--) { S[i] = S[i+1] + A[i+1].second; }

        ll sum = 0;
        for (int i = 0; i < N; i++) {
            sum += A[i].first * 2 * S[i];
        }
        printf("%lld\n", sum);
    }
}
