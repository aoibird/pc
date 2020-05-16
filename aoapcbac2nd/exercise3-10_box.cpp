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

const int N = 6;
PII S[N];

int main()
{
    int w, h;
    while (scanf("%d%d", &w, &h) == 2) {
        for (int i = 0; i < N; i++) {
            if (i != 0) scanf("%d%d", &w, &h);
            if (w > h) swap(w, h);
            S[i] = PII(w, h);
        }

        sort(S, S+N);
        // for (int i = 0; i < N; i++) {
        //     printf("(%d %d) ", S[i].first, S[i].second);
        // }
        // printf("\n");

        bool pair = true;
        for (int i = 0; i < N/2; i++) {
            int wi = S[i*2].first, hi = S[i*2].second;
            int wj = S[i*2+1].first, hj = S[i*2+1].second;
            // printf("%d %d %d %d\n", wi, wj, hi, hj);
            if (wi != wj || hi != hj) { pair = false; break; }
        }

        int wa = S[0].first, ha = S[0].second;
        int wb = S[2].first, hb = S[2].second;
        int wc = S[4].first, hc = S[4].second;
        // printf("%d %d %d %d %d %d (%d)\n", wa, ha, wb, hb, wc, hc, (int)pair);
        if (pair && wa == wb &&
            ((ha==wc && hb==hc) || (ha==hc && hb==wc))) pair = true;
        else if (pair && wa == hb &&
                 ((ha==wc && wb==hc) || (ha==hc && wb==wc))) pair = true;
        else if (pair && wa == wc &&
                 ((ha==hb && hc==wb) || (ha==wb && hc==hb))) pair = true;
        else if (pair && wa == hc &&
                 ((ha==hb && wc==wb) || (ha==wb && wc==hb))) pair = true;
        else pair = false;

        if (pair) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
}
