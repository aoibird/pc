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
    mat B(A.size(), vec(A[0].size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    for (int x = n; x > 0; x >>= 1) { if (x&1) B = mul(B, A); A = mul(A, A); }
    return B;
}

void set_identity(mat &A) { for (int i = 0; i <= N; i++) A[i][i] = 1; }

void solve()
{
    mat A(N+1, vec(N+1, 0)); set_identity(A);
    for (int k = 0; k < K; k++) {
        int cmd = O[k], i = I[k], j = J[k];
        mat B(N+1, vec(N+1, 0)); set_identity(B);
        if (cmd == 'g') { B[i][0] = 1; }
        else if (cmd == 'e') { B[i][i] = 0; }
        else if (cmd == 's') { B[i][i] = B[j][j] = 0; B[i][j] = B[j][i] = 1; }
        else ;
        A = mul(B, A);
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
