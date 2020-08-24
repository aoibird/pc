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

// const int BASE = 1e9;
const int MAXN = 2500000+10;
char SL[MAXN], SR[MAXN];
int table[3][4] = {{9, 0, 9, 1}, {0, 5, 1, 5}, {0, 9, 1, 9}};

void rev(char *S, int N) { for (int i = 0; i < N/2; i++) swap(S[i], S[N-i-1]); }

void trim_print(char *S, int N)
{
    int s = 0; while (s < N-1 && S[s] == '0') s++;
    printf("%s", S+s);
}

void minus_from(char *S, int N, int t)
{
    char D[40]; sprintf(D, "%d", t); int L = strlen(D); rev(D, L);
    rev(S, N);
    // printf("S = %s D = %s\n", S, D);
    for (int i = 0, carry = 0; i<L || i<N || carry!=0; i++) {
        int x = (i < N) ? S[i]-'0' : 0;
        int y = (i < L) ? D[i]-'0' : 0;
        int z = x - y - carry;
        if (z < 0) z += 10, carry = 1;
        else carry = 0;
        S[i] = z + '0';
    }
    rev(S, N);
}

int main()
{
    int N;
    while (scanf("%d", &N) == 1) {
        for (int i = 0; i < N; i++) {
            SL[i] = '0' + table[(i>=2 ? 2 : i)][(i != N-1 ? 0 : 2) + 0]; // minimum power
            SR[i] = '0' + table[(i>=2 ? 2 : i)][(i != N-1 ? 0 : 2) + 1]; // maximum power
        }
        SL[N] = SR[N] = '\0';
        int tl = 0; for (int i = 0; i < N; i++) tl += (SL[i]-'0')*(SL[i]-'0');
        int tr = 0; for (int i = 0; i < N; i++) tr += (SR[i]-'0')*(SR[i]-'0');
        for (int i = 0; i < N/2; i++) swap(SL[i], SL[N-i-1]);
        for (int i = 0; i < N/2; i++) swap(SR[i], SR[N-i-1]);
        // printf("SL = %s SR = %s\n", SL, SR);
        // printf("tl = %d tr = %d\n", tl, tr);
        if (N < 10) {
            int l; sscanf(SL, "%d", &l);
            int r; sscanf(SR, "%d", &r);
            printf("%d\n%d\n%d\n%d\n", r, l, r-tr, l-tl);
        }
        else {
            printf("%s\n%s\n", SR, SL);
            minus_from(SL, N, tl);
            minus_from(SR, N, tr);
            trim_print(SR, N); printf("\n");
            trim_print(SL, N); printf("\n");
        }
        // printf("\n");

    }
}
