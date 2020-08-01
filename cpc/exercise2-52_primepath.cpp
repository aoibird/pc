// POJ 3126
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<string,int> PSI;

const int MAXN = 10000;
bool prime[MAXN];
map<string,bool> vis;
char S[10];
char T[10];

void sieve(int n)
{
    for (int i = 0; i < MAXN; i++) prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (prime[i]) for (int j = 2*i; j < MAXN; j += i) prime[j] = false;
    }
}

void print_array(bool *a, int n)
{
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i==n-1?'\n':' ');
}


void solve()
{
    sieve(MAXN);
    string s = S, t = T;
    // printf("%s -> %s\n", s.c_str(), t.c_str());
    // print_array(prime, MAXN);
    if (!prime[atoi(t.c_str())]) { printf("Impossible\n"); return; }

    queue<PSI> q; q.push(PSI(s, 0));
    vis.clear();
    while (!q.empty()) {
        PSI p = q.front(); q.pop();
        string curr = p.first; int step = p.second;
        // printf("%s (%d)\n", curr.c_str(), step);
        if (curr == t) { printf("%d\n", step); return; }
        for (int i = 0; i < 4; i++) {
            for (int d = '0'; d <= '9'; d++) {
                if (curr[i] == d || (i == 0 && d == '0')) continue;
                int prev = curr[i];
                curr[i] = d;
                if (vis.find(curr) == vis.end() && prime[atoi(curr.c_str())]) {
                    q.push(PSI(curr, step+1));
                    vis[curr] = true;
                }
                curr[i] = prev;
            }
        }
    }
    printf("Impossible\n");
}

int main()
{
    int TC; scanf("%d", &TC); getchar();
    for (int i = 0; i < TC; i++) {
        scanf("%s%s", S, T);

        solve();
    }
}
