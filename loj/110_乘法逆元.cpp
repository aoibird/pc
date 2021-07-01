// LOJ 110 乘法逆元
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

int N, P;

void extgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0) { x = 1; y = 0; }
    else { extgcd(b, a % b, y, x); y -= (a / b) * x; }
}

int main()
{
    scanf("%d%d", &N, &P);
    for (int i = 1; i <= N; i++) {
        ll x, y;
        extgcd(i, P, x, y);
        printf("%lld\n", (x+P)%P);
    }
}
