// POJ 3421
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> PII;

map<int,int> factor;

void prime_factor(int n)
{
    for (int i = 2; i*i <= n; i++) {
        while (n % i == 0) { factor[i] += 1; n /= i; }
    }
    if (n != 1) factor[n] = 1;
}

int main()
{
    ll N, L, P;
    while (scanf("%lld", &N) == 1) {
        factor.clear();
        prime_factor(N);

        L = 0;
        for (map<int,int>::iterator it = factor.begin();
             it != factor.end(); it++) {
            L += it->second;
        }

        P = 1;
        for (int i = 2; i <= L; i++) { P *= i; }
        for (map<int,int>::iterator it = factor.begin();
             it != factor.end(); it++) {
            int s = it->second;
            for (int j = 1; j <= s; j++) P /= j;
        }

        printf("%lld %lld\n", L, P);
    }
}
