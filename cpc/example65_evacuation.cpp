// POJ 3057 Evacuation
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

const int MAXRC = 12+2;
int R, C;
char field[MAXRC][MAXRC];
vector<PII> doors;
vector<PII> people;
int dist[MAXRC][MAXRC][MAXRC][MAXRC];

const int MAXV = 1e5;
vector<int> G[MAXV];
int match[MAXV];
bool used[MAXV];

const int dr[4] = {-1, 0, 0, 1};
const int dc[4] = {0, -1, 1, 0};

void add_edge(int u, int v) { G[u].push_back(v); G[v].push_back(u); }

bool dfs(int v)
{
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) { match[v] = u, match[u] = v; return true; }
    }
    return false;
}

void bfs(int r, int c, int d[MAXRC][MAXRC])
{
    queue<int> qr, qc;
    d[r][c] = 0; qr.push(r); qc.push(c);
    while (!qr.empty()) {
        int r = qr.front(); qr.pop(); int c = qc.front(); qc.pop();
        for (int k = 0; k < 4; k++) {
            int tr = r + dr[k], tc = c + dc[k];
            if (0 <= tr && tr < R && 0 <= tc && tc < C
                && field[tr][tc] == '.' && d[tr][tc] < 0) {
                d[tr][tc] = d[r][c] + 1; qr.push(tr); qc.push(tc);
            }
        }
    }
}

int solve()
{
    doors.clear(); people.clear(); memset(dist, -1, sizeof(dist));
    for (int i = 0; i < MAXV; i++) G[i].clear();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (field[i][j] == 'D') { doors.push_back(PII(i, j)); bfs(i, j, dist[i][j]); }
            if (field[i][j] == '.') { people.push_back(PII(i, j)); }
        }
    }

    int n = R * C, nd = doors.size(), np = people.size();
    for (int i = 0; i < nd; i++) {
        for (int j = 0; j < np; j++) {
            int t = dist[doors[i].first][doors[i].second][people[j].first][people[j].second];
            if (t >= 0) { for (int k = t; k <= n; k++) add_edge((k-1)*nd+i, n*nd+j); }
        }
    }

    if (np == 0) return 0;
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < n * nd; v++) {
        memset(used, 0, sizeof(used));
        cnt += dfs(v);
        if (cnt == np) return v/nd+1;
    }
    return -1;
}

void strip() { int ch; while ((ch = getchar()) != EOF && ch != '\n') ; }

int main()
{
    int TC; scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        scanf("%d%d", &R, &C); strip();
        for (int i = 0; i < R; i++) scanf("%s", field[i]);

        int res = solve();
        if (res == -1) printf("impossible\n");
        else printf("%d\n", res);
    }
}
