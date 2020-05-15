// UVa 1220
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

const int MAXN = 200+10;
// const int MAXL = 100+20;
map<string,int> names;
vector<int> ems[MAXN];
int N;
int dp[MAXN][2];
int only[MAXN][2];

void print()
{
    for (map<string,int>::iterator it = names.begin();
         it != names.end(); it++)
        cout << it->first << " " << it->second << "\n";
    for (int i = 0; i < N; i++) {
        printf("%d: ", i);
        for (int j = 0; j < ems[i].size(); j++) printf("%d ", ems[i][j]);
        printf("\n");
    }
}

void print_table()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d(%d) ", dp[i][j], only[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isonly(int v)
{
    if (dp[v][0] == dp[v][1]
        || (dp[v][0] > dp[v][1] && only[v][0] == 0)
        || (dp[v][0] < dp[v][1] && only[v][1] == 0)) {
        return false;
    }
    else return true;
}

void dfs(int u, int select)
{
    if (ems[u].size() == 0) {
        dp[u][select] = select;
        only[u][0] = only[u][1] = 1;
        return;
    }
    if (dp[u][select] != 0) return;

    if (select) {
        // printf("%d select\n", u);
        dp[u][1] = 1;
        only[u][1] = 1;
        for (int i = 0; i < ems[u].size(); i++) {
            int v = ems[u][i];
            dfs(v, 0);
            // printf("    %d %d\n", dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];

            if (only[v][0] == 0) only[u][1] = 0;
        }
    }
    else {
        // printf("%d not select\n", u);
        dp[u][0] = 0;
        only[u][0] = 1;
        for (int i = 0; i < ems[u].size(); i++) {
            int v = ems[u][i];
            dfs(v, 0); dfs(v, 1);
            // printf("    %d %d\n", dp[v][0], dp[v][1]);
            dp[u][0] += max(dp[v][0], dp[v][1]);

            if (!isonly(v)) only[u][0] = 0;
        }
    }
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        memset(dp, 0, sizeof(dp));
        memset(only, 0, sizeof(only));
        names.clear();
        for (int i = 0; i < N; i++) ems[i].clear();

        string boss, a, b;
        cin >> boss;
        names[boss] = 0;
        for (int i = 1; i <= N-1; i++) {
            cin >> a >> b;
            names[a] = i; ems[names[b]].push_back(names[a]);
        }
        // print();

        dfs(0, 0); dfs(0, 1);
        printf("%d ", max(dp[0][0], dp[0][1]));
        if (!isonly(0)) printf("No\n");
        else printf("Yes\n");
    }
}
