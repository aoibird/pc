// Codeforces 102460 H Mining a
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int TC; scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        ll n; scanf("%lld", &n);
        ll b = n+1;
        ll axorb = n * b;
        ll a = axorb ^ b;
        printf("%lld\n", a);
    }
}
