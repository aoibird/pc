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

// const int MAXN = 100000+5;
vector<int> P;
int N;


int main()
{
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) { int pi; scanf("%d", &pi); P.push_back(pi); }
        int o; scanf("%d", &o);

        sort(P.begin(), P.end());
        P.erase(unique(P.begin(), P.end()), P.end());
        // for (int i = 0; i < P.size(); i++) printf("%d ", P[i]); printf("\n");
        ll k = 1;
        for (int i = 0; i < P.size(); i++) k = (k * P[i]) % o;
        k = (k - 1 + o) % o;

        if (k == 0) printf("YES\n");
        else printf("NO\n");
    }
}
