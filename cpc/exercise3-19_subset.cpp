// POJ 3977 Subset
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
typedef pair<ll,int> PLI;

const int MAXN = 35+5;
ll A[MAXN];
vector<PLI> S1;
vector<PLI> S2;
int N;
ll mval;
int mlen;

void print_vector(vector<PLI> v)
{
    for (int i = 0; i < v.size(); i++)
        printf("(%lld %d)%c", v[i].first, v[i].second, i+1==v.size()?'\n':' ');
}

void calc(int start, int N, vector<PLI> &S)
{
    for (int s = 1; s < (1<<N); s++) {
        ll sum = 0; int cnt = 0;
        for (int i = 0; i < N; i++) if ((s>>i)&1) { sum += A[start+i]; cnt++; }
        S.push_back(PLI(sum, cnt));
        ll abssum = sum > 0 ? sum : -sum;
        if (abssum < mval || (abssum==mval && cnt<mlen))
            mval = abssum, mlen = cnt;
    }
    sort(S.begin(), S.end());
    // print_vector(S);
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
        S1.resize(0); S2.resize(0);

        mval = A[0] > 0 ? A[0] : -A[0], mlen = 1;
        for (int i = 0; i < N; i++) mval = min(mval, (A[i]>0 ? A[i] : -A[i])); // size == 1

        calc(0, N/2, S1);
        calc(N/2, N-N/2, S2);
        for (int i = 0; i < S1.size(); i++) {
            ll val = S1[i].first, len = S1[i].second;
            int p = lower_bound(S2.begin(), S2.end(), PLI(-val, 0)) - S2.begin();
            for (int j = p-1; j <= p+1; j++) {
                if (j < 0 || j >= S2.size()) continue;
                ll v = S2[j].first; int l = S2[j].second;
                ll abssum = (val + v > 0) ? val + v : - val - v;
                if (abssum < mval || (abssum==mval && len+l<mlen))
                    mval = abssum, mlen = len + l;
            }
            // printf("%lld (%lld) %lld (%lld)\n", val, len, v, l);
        }

        printf("%lld %d\n", mval, mlen);
    }
}
