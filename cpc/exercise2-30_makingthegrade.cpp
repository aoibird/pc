// POJ 3666
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

const int MAXN = 2000+10;
int A[MAXN];
int B[MAXN];
int N;

int solve()
{
    for (int i = 0; i < N; i++) B[i] = A[i];
    int sum = 0;
    for (int i = 1; i < N-1; i++) {
        if (B[i] > B[i-1] && B[i] > B[i+1]) {
            int m =  max(B[i-1], B[i+1]);
            sum += B[i] - m;
            B[i] = m;
        }
        else if (B[i] < B[i-1] && B[i] < B[i+1]) {
            int m = min(B[i-1], B[i+1]);
            sum += m - B[i];
            B[i] = m;
        }
        else {}
    }
    return sum;
}

int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) { scanf("%d", &A[i]); }
        int x = solve();
        for (int i = 0; i < N/2; i++) swap(A[i], A[N-i-1]);
        int y = solve();
        printf("%d\n", min(x, y));
    }
}
