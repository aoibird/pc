// POJ 3735 Training little cats
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
typedef vector<ll> vec;
typedef vector<vec> mat;

const int MAXK = 100+5;
int O[MAXK], I[MAXK], J[MAXK];
int N, M, K;

void print_matrix(const mat &A)
{
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) printf("%lld ", A[i][j]);
        printf("\n");
    }
}

mat mul(mat &A, mat &B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < B.size(); k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < B[0].size(); j++) {
                if (B[k][j] == 0) continue;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

mat pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    while (n > 0) { if (n&1) B = mul(B, A); A = mul(A, A); n>>=1; }
    return B;
}

void set_identity(mat &A) {
    for (int i = 0; i <= N; i++) A[i][i] = 1;
}

void solve()
{
    mat A(N+1, vec(N+1, 0)); set_identity(A);
    mat B(N+1, vec(N+1, 0)); set_identity(B);
    for (int k = 0; k < K; k++) {
        int cmd = O[k], i = I[k], j = J[k];
        if (cmd == 'g') { A[i][0]++; }
        else if (cmd == 'e') { for (int c = 0; c <= N; c++) A[i][c] = 0; }
        else if (cmd == 's') { for (int c = 0; c <= N; c++) swap(A[i][c], A[j][c]); }
        else ;
    }
    A = pow(A, M);
    for (int i = 1; i <= N; i++) printf("%lld%c", A[i][0], i==N?'\n':' ');
}

int main()
{
    while (scanf("%d%d%d", &N, &M, &K) == 3 && N) {
        for (int i = 0; i < K; i++) {
            char cmd[5]; scanf("%s", cmd);
            O[i] = cmd[0];
            if (cmd[0] == 'e') scanf("%d", &I[i]);
            else if (cmd[0] == 'g') scanf("%d", &I[i]);
            else if (cmd[0] == 's') scanf("%d%d", &I[i], &J[i]);
            else ;
        }

        solve();
    }
}
