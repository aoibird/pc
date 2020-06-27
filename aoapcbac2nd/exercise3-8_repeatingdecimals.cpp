// UVa 202
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

int a, b; // <= 3000
vector<int> Q;
vector<int> R;
map<int, int> RL;

void solve()
{
    int left = 0, right = 0;
    int integral = a / b;
    int at = a % b;
    for (int i = 0; ; i++) {
        Q.push_back(at / b);
        R.push_back(at % b);
        if (RL.count(at % b) == 0) { RL[at % b] = i; }
        else { left = RL[at % b] + 1; right = i + 1; break; }
        at = (at % b) * 10;
        // printf("a = %d\n", a);
    }
    // printf("=================================\n");
    // printf("integral, left, right: %d %d %d\n", integral, left, right);
    // for (int i = 0; i < Q.size(); i++)
    //     printf("%d%c", Q[i], i==Q.size()-1?'\n':' ');
    // for (int i = 0; i < R.size(); i++)
    //     printf("%d%c", R[i], i==R.size()-1?'\n':' ');

    printf("%d/%d = %d.", a, b, integral);
    for (int i = 1; i < left; i++) printf("%d", Q[i]);
    printf("(");
    for (int i = left; i < right && i<=50; i++) printf("%d", Q[i]);
    printf("%s)\n", right-left>=50?"...":"");
    printf("   %d = number of digits in repeating cycle\n\n", right-left);

}

int main()
{
    while (scanf("%d%d", &a, &b) == 2) {
        Q.resize(0);
        R.resize(0);
        RL.clear();
        solve();
    }
}
