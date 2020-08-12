// POJ 3185
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

const int MAXN = 20+5;
const int N = 20;
int A[MAXN];
int flip[MAXN];

int flipit()
{
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if ((A[i-1] + flip[i-1])%2 == 1) {
            flip[i-1]++; flip[i]++; flip[i+1]++;
            cnt++;
        }
        else ;
    }
    return cnt;
}

int main()
{
    while (scanf("%d", &A[0]) == 1) {
        for (int i = 1; i < N; i++) scanf("%d", &A[i]);

        int cnt = 0;
        memset(flip, 0, sizeof(flip));
        if (A[0] == 1) {
            flip[0] = flip[1] = 1;
            int cnt1 = flipit() + 1;
            memset(flip, 0, sizeof(flip));
            int cnt2 = flipit();

            cnt = min(cnt1, cnt2);
        }
        else {
            cnt = flipit();
        }

        printf("%d\n", cnt);
    }
}
