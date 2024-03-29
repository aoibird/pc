// AOJ NTL_1_D Euler's Phi Function
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;


int main()
{
    int n; scanf("%d", &n);
    int f = n;
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) { f = f / i * (i - 1); }
        while (n%i == 0) { n /= i; }
    }
    if (n != 1) { f = f / n * (n - 1); }
    printf("%d\n", f);
}
