// POJ 1862
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;


int main()
{
    priority_queue<double> pq;
    int N;
    while (scanf("%d", &N) == 1) {
        while (!pq.empty()) pq.pop();
        for (int i = 0; i < N; i++) { int a; scanf("%d", &a); pq.push((double)a); }
        while (pq.size() > 1) {
            double x = pq.top(); pq.pop();
            double y = pq.top(); pq.pop();
            pq.push(2 * sqrt(x * y));
        }
        printf("%.3f\n", pq.top());
    }
}
