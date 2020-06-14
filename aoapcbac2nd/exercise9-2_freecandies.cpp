// UVa 10118
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int KIND = 20;
const int P = 4;
const int MAXN = 40+5;
vector<int> A[P];
int N;
int dp[MAXN][MAXN][MAXN][MAXN];

void print_piles()
{
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < A[i].size(); j++) printf("%d ", A[i][j]);
        printf("\n");
    }
}

int count_bit(int set)
{
    int cnt = 0;
    for (int i = 0; i <= KIND; i++) {
        if ((set>>i)&1) cnt++;
    }
    return cnt;
}

int dfs(int a, int b, int c, int d, int set)
{
    if (count_bit(set) == 5) return 0;
    int &ret = dp[a][b][c][d];

    if (ret) {
        return ret;
    }
    else {
        ret = 0;
        int s[4] = {a, b, c, d};
        for (int i = 0; i < P; i++) {
            if (s[i] >= N) continue;

            int type = A[i][s[i]];
            int cnt = (set>>type)&1;
            s[i] += 1;
            ret = max(ret, cnt + dfs(s[0], s[1], s[2], s[3], set^(1<<type)));
            s[i] -= 1;
        }
        return ret;
    }
}


int main()
{
    while (scanf("%d", &N) == 1 && N) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < P; i++) A[i].resize(0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                int x; scanf("%d", &x);
                A[j].push_back(x);
            }
        }
        // print_piles();

        printf("%d\n", dfs(0, 0, 0, 0, 0));
    }
}
