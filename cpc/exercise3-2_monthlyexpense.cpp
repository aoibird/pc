// POJ 3273
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

const int MAXN = 100000+10;
int A[MAXN];
int N, M, SUM;

bool can(int s)
{
    int curr = 0, sum;
    for (int i = 0; i < M; i++) {
        sum = 0;
        while (curr < N && sum + A[curr] <= s) { sum += A[curr]; curr++; }
    }
    return curr == N;
}

int main()
{
    while (scanf("%d%d", &N, &M) == 2) {
        SUM = 0;
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]); SUM += A[i]; }
        int lb = 0, ub = SUM, res = 0;
        while (lb < ub) {
            int mid = (lb+ub)/2;
            if (can(mid)) { ub = mid; res = mid; }
            else { lb = mid+1; }
        }
        printf("%d\n", res);
    }
}
