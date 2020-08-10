// POJ 2739
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

const int MAXN = 10000 + 10;
bool isprime[MAXN];
vector<int> primes;
int N;

void sieve()
{
    fill(isprime, isprime+MAXN, true);
    for (int i = 2; i < MAXN; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = i*i; j < MAXN; j += i) isprime[j] = false;
        }
    }
}

int main()
{
    sieve();
    // for (int i = 0; i < primes.size(); i++)
    //     printf("%d%c", primes[i], i==primes.size()-1?'\n':' ');
    while (scanf("%d", &N) == 1 && N) {
        int l = 0, r = 0, sum = 0, cnt = 0;
        while (true) {
            while (r < primes.size() && primes[r] < N && sum < N) { sum += primes[r++]; }
            if (sum < N) break;

            if (sum == N) cnt++;
            sum -= primes[l++];
        }
        printf("%d\n", cnt + isprime[N]);
    }
}
