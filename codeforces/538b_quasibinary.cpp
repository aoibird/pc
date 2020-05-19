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

const int MAXL = 100;
char S[MAXL];
int N, L;
vector<string> V;

string substract(int x)
{
    char str[MAXL];
    int n = 0;
    for (int i = x; i < L; i++) {
        if (S[i] > '0') { S[i] -= 1; str[n++] = '1'; }
        else str[n++] = '0';
    }
    str[n++] = '\0';
    return string(str);
}

void solve()
{
    for (int i = 0; i < L; i++) {
        if (S[i] == '0') continue;

        while (S[i] != '0') V.push_back(substract(i));
    }
    int cnt = V.size();
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%s%c", V[i].c_str(), i==cnt-1?'\n':' ');
}

int main()
{
    while (scanf("%d", &N) == 1) {
        memset(S, 0, sizeof(S));
        V.clear();

        sprintf(S, "%d", N);
        L = strlen(S);
        // printf("%d %s\n", N, S);

        solve();
    }
}
