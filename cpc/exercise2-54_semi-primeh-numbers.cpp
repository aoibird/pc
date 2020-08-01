// POJ 3292
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

const int MAXN = 1000001+10;
bool isprime[MAXN];
bool vis[MAXN];
vector<int> prime;
vector<int> semiprime;
int N;

void print_array(bool *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


void sieve()
{
    prime.resize(0); semiprime.resize(0);
    memset(vis, false, sizeof(vis)); memset(isprime, true, sizeof(isprime));
    for (int i = 5; i < MAXN; i+=4) {
        if (isprime[i]) {
            prime.push_back(i);
            for (int j = i*2; j < MAXN; j += i) isprime[j] = false;
            for (int j = 0; j < prime.size(); j++) {
                int p = prime[j];
                if (MAXN / i >= p && !vis[i*p]) {
                    semiprime.push_back(i * p);
                    vis[i*p] = true;
                }
                if (MAXN / i < p) break;
            }
        }
    }
    sort(semiprime.begin(), semiprime.end());
}

int main()
{
    sieve();
    while (scanf("%d", &N) == 1 && N) {
        int p = upper_bound(semiprime.begin(), semiprime.end(), N)-semiprime.begin();
        printf("%d %d\n", N, p);
    }
}
