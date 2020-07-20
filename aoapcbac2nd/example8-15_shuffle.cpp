// UVa 12174
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 100000 + 10;
int CNT[MAXN];
vector<int> V;
set<int> MUL;
map<int,bool> SAT;
int N, S;

void print_cnt()
{
    printf("CNT = ");
    for (int i = 0; i <= S; i++) { printf("%d%c", CNT[i], i==S?'\n':' '); }
}

void print_mul()
{
    printf("MUL = ");
    for (set<int>::iterator it = MUL.begin();
         it != MUL.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
}

bool satisfy(int x)
{
    for (int i = x; i < N; i += S) {
        if (SAT[i] == false) return false;
    }
    return true;
}

void solve()
{
    N = V.size();
    // for (int i = 0; i < N; i++) { printf("%d%c", V[i], i==N-1?'\n':' '); }

    for (int i = 0; i < S; i++) CNT[V[i]] += 1;
    for (int i = S; i < N; i++) {
        CNT[V[i-S]] -= 1;
        CNT[V[i]] += 1;
        if (V[i-S] != 0 && CNT[V[i-S]] == 1) MUL.erase(V[i-S]);
        if (V[i] != 0 && CNT[V[i]] >= 2) MUL.insert(V[i]);

        if (MUL.size() == 0) SAT[i] = true;
        else SAT[i] = false;

        // printf("[%d] %d ok? %d\n", i, V[i], SAT[i]);
        // print_cnt();
        // print_mul();
    }

    int cnt = 0;
    for (int i = S; i < 2*S; i++) {
        // printf("%d -> ok? %d\n", i, satisfy(i));
        if (satisfy(i)) cnt++;
    }
    printf("%d\n", cnt);
}

int main()
{
    int TC; scanf("%d", &TC);
    for (int tc = 0; tc < TC; tc++) {
        V.resize(0);
        memset(CNT, 0, sizeof(CNT));
        MUL.clear();
        scanf("%d%d", &S, &N);
        for (int i = 0; i < S; i++) { V.push_back(0); }
        for (int i = 0; i < N; i++) { int a; scanf("%d", &a); V.push_back(a); }
        for (int i = 0; i < S; i++) { V.push_back(0); }
        solve();
    }
}
