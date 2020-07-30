// POJ 2010
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

struct Calf {
    int index, score, aid;
    Calf(int i=0, int s=0, int a=0) { index=i; score=s; aid=a; }
};

//const int INF = 2 * 1e9 + 10;
const int MAXC = 1e5+10;
Calf A[MAXC]; // (score, finanicial aid) score_i < score_j
Calf S[MAXC]; // aid_i < aid_j
int N, C, F;

bool cmp_score(const Calf &a, const Calf &b)
{
    return a.score < b.score || (a.score==b.score && a.aid < b.aid);
}

bool cmp_aid(const Calf &a, const Calf &b)
{
    return a.aid < b.aid || (a.aid==b.aid && a.index < b.index);
}

void print_array(Calf *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("(%d %d %d)%c", a[i].index, a[i].score, a[i].aid, i==n-1?'\n':' ');
}


void solve()
{
    sort(A, A+C, cmp_score);
    for (int i = 0; i < C; i++) { A[i].index = i; }
    for (int i = 0; i < C; i++) { S[i] = A[i]; }
    sort(S, S+C, cmp_aid);

    // print_array(A, C);
    // print_array(S, C);
    int bestm = 0;
    for (int i = 0; i < C; i++) {
        int index = A[i].index, aid = A[i].aid;
        // printf("median %d %d %d\n", index, score, aid);
        int sumback = 0, tback = 0;
        for (int j = 0; j < C && tback < N/2; j++) {
            if (S[j].index < index) { sumback += S[j].aid; tback++; }
        }
        if (tback != N/2) continue;
        int sumfront = 0, tfront = 0;
        for (int j = 0; j < C && tfront < N/2; j++) {
            if (S[j].index > index) { sumfront += S[j].aid; tfront++; }
        }
        if (tfront != N/2) continue;
        int sum = sumback+sumfront+aid;
        // printf("sum %d = %d(%d) + %d(%d) + %d\n",
        //        sum, sumback, tback, sumfront, tfront, aid);
        if (sum <= F) { bestm = i; }
    }
    printf("%d\n", A[bestm].score);
}

int main()
{
    while (scanf("%d%d%d", &N, &C, &F) == 3) {
        for (int i = 0; i < C; i++) {
            int s, a; scanf("%d%d", &s, &a);
            A[i] = Calf(0, s, a);
        }
        solve();
    }
}
