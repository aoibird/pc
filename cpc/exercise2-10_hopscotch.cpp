// POJ 3050
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int N = 5;
int F[N][N];
set<string> S;
vector<int> V;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c, int depth)
{
    if (depth == N) {
        char str[20];
        for (int i = 0; i < V.size(); i++) {str[i] = V[i]+'0';} str[V.size()] = '\0';
        string s = str;
        S.insert(s);
        // printf("%s\n", str);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
            V.push_back(F[nr][nc]);
            dfs(nr, nc, depth+1);
            V.pop_back();
        }
    }
}


int main()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &F[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            V.push_back(F[i][j]);
            dfs(i, j, 0);
            V.pop_back();
        }
    }
    printf("%lu\n", S.size());
    // for (set<string>::iterator it = S.begin(); it != S.end(); it++)
    //     printf("%s\n", (*it).c_str());
}
