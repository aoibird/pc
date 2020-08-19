// Luogu 1601 A+B Problem（高精）
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

const int MAXL = 500+10;
const int BASE = 10;
char A[MAXL], B[MAXL];
char C[MAXL];

int main()
{
    while (scanf("%s%s", A, B) == 2) {
        memset(C, 0, sizeof(C));
        int LA = strlen(A), LB = strlen(B);
        for (int i = 0; i < LA/2; i++) swap(A[i], A[LA-i-1]);
        for (int i = 0; i < LB/2; i++) swap(B[i], B[LB-i-1]);
        int LC = 0;
        for (int i = 0, carry = 0; i<LA||i<LB||carry!=0; i++, LC++) {
            int x = (i < LA) ? A[i] - '0' : 0;
            int y = (i < LB) ? B[i] - '0' : 0;
            int z = x + y + carry;
            carry = z / BASE;
            C[i] = z % BASE;
        }
        while (C[LC-1] == 0 && LC > 1) LC--;
        for (int i = LC-1; i >= 0; i--) { printf("%c", C[i]+'0'); } printf("\n");
    }
}
