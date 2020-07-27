// POJ 3046
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXA = 1e5+20;
int ANTS[MAXA];
int T, A, S, B;
queue<int> Q;

int main()
{
    vector<int> t;
    while (scanf("%d%d%d%d", &T, &A, &S, &B) == 4) {
        while (!Q.empty()) Q.pop();
        for (int i = 0; i < A; i++) scanf("%d", &ANTS[i]);
        sort(ANTS, ANTS+A);

        int cnt = 0;
        for (int i = 0; i <= B && i <= A; i++) {
            // printf("[%d] %d\n", i, (int)Q.size());
            if (i >= S && i <= B) cnt += Q.size();
            if (Q.empty()) {
                for (int i = 0; i < A; i++) {
                    if (i == 0 || ANTS[i] != ANTS[i-1]) { Q.push(i); }
                }

            }
            else {
                t.resize(0);
                while (!Q.empty()) {
                    int x = Q.front(); Q.pop();
                    for (int i = x+1; i < A; i++) {
                        if (i == x+1 || ANTS[i] != ANTS[i-1]) { t.push_back(i); }
                    }
                }
                for (int i = 0; i < t.size(); i++) Q.push(t[i]);
            }
        }
        printf("%d\n", cnt);
    }
}
