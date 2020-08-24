#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXL = 500000+10;
char S[MAXL];
int L;

bool ispalin(char *S, int l, int r) // [l, r]
{
    for ( ; l < r; l++, r--) { if (S[l] != S[r]) return false; }
    return true;
}

int main()
{
    while (scanf("%s", S) == 1) {
        L = strlen(S);
        bool same = true, palin = false;
        for (int i = 0; i < L/2; i++) {
            if (S[i] == S[L-i-1]) continue;
            same = false;
            for (int j = i+1; j < L-i-1; j++) {
                if (S[j] == S[L-i-1]) {
                    swap(S[i], S[j]);
                    if (ispalin(S, i, L-i-1)) { palin = true; break; }
                    swap(S[i], S[j]);
                }
                if (S[j] == S[i]) {
                    swap(S[L-i-1], S[j]);
                    if (ispalin(S, i, L-i-1)) { palin = true; break; }
                    swap(S[L-i-1], S[j]);
                }
            }
            break;
        }

        if (same || ((!same) && palin)) printf("YES\n");
        else printf("NO\n");
    }
}
