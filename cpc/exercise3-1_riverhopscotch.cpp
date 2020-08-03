// POJ 3258
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

vector<int> V;
int L, N, M;
int T;

bool can(int x)
{
    int last = 0;
    int cnt = 0;
    for (int i = 1; i < V.size(); i++) {
        if (V[i]-V[last] >= x) last = i;
        else cnt++;
    }
    return cnt < M && last == V.size()-1;
}

int main()
{
    while (scanf("%d%d%d", &L, &N, &M) == 3) {
        V.resize(0);
        V.push_back(0); V.push_back(L);
        for (int i = 0; i < N; i++) {
            int a; scanf("%d", &a);
            V.push_back(a);
        }
        N += 2;

        sort(V.begin(), V.end());
        int lb = 0, ub = L+1, mid;
        while (lb + 1 < ub) {
            mid = (lb+ub)/2;
            if (can(mid)) lb = mid;
            else ub = mid;
        }
        printf("%d\n", ub);
    }
}
