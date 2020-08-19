// Luogu 1005 矩阵取数游戏
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

struct BigInt {
    static const ll MOD = 1e18;
    ll hi, lo;
    BigInt(ll h=0, ll l=0) { hi=h; lo=l; }
    BigInt(int a) { hi = 0; lo = a; }
    BigInt operator+(const BigInt &a) const {
        BigInt c(hi, lo);
        c.lo += a.lo, c.hi += a.hi;
        if (c.lo >= MOD) c.lo -= MOD, c.hi += 1;
        return c;
    }
    BigInt operator*(const int &a) const {
        BigInt c(hi, lo);
        c.lo *= a, c.hi *= a;
        if (c.lo >= MOD) c.lo -= MOD, c.hi += 1;
        return c;
    }
    bool operator>(const BigInt &a) const {
        return hi>a.hi || (hi==a.hi && lo > a.lo);
    }
    void print() {
        if (hi) printf("%lld%018lld", hi, lo);
        else printf("%lld", lo);
    }
};

const int MAXN = 80+5;
const int MAXM = 80+5;
int matrix[MAXN][MAXM];
int N, M;
BigInt dp[MAXM][MAXM];


BigInt solve(int x)
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++) dp[i][j] = BigInt(0);
    for (int i = 0; i < M; i++) dp[i][i] = BigInt(matrix[x][i]);
    for (int i = M-2; i >= 0; i--) {
        for (int j = i+1; j < M; j++) {
            BigInt a = BigInt(matrix[x][i]) + dp[i+1][j]*2;
            BigInt b = BigInt(matrix[x][j]) + dp[i][j-1]*2;
            dp[i][j] = (a > b) ? a : b;
        }
    }
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < M; j++) { dp[i][j].print(); printf(" "); }
    //     printf("\n");
    // }
    return dp[0][M-1] * 2;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) scanf("%d", &matrix[i][j]);
    }

    BigInt sum = 0;
    for (int i = 0; i < N; i++) sum = sum + solve(i);
    sum.print(); printf("\n");
}
