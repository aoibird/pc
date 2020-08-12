// POJ 2674
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

const int MAXN = 32000+10;
bool DIR[MAXN];
double POS[MAXN];
string NAME[MAXN];
int N;
double L, V;

void input()
{
    scanf("%lf%lf", &L, &V);
    int ch; while ((ch = getchar()) != '\n') ;
    char line[400], s[260];
    for (int i = 0; i < N; i++) {
        int p = 0;
        while ((ch = getchar()) != EOF && ch != '\n') line[p++] = ch;
        line[p++] = '\0';
        if (line[0] == 'p') DIR[i] = true;
        else if (line[0] == 'n') DIR[i] = false;
        else ;
        int t = 1;
        while (line[t] == ' ') t++;
        sscanf(line+t, "%lf", &POS[i]);
        while (line[t] != ' ') t++;
        while (line[t] == ' ') t++;
        sscanf(line+t, "%s", s); NAME[i] = s;
        // printf("%d %lf %s\n", DIR[i], POS[i], NAME[i].c_str());
    }
}

int main()
{
    while (scanf("%d", &N) == 1 && N) {
        input();

        double maxdist = 0;
        for (int i = 0; i < N; i++) {
            double dist = (DIR[i]) ? L-POS[i] : POS[i]-0;
            maxdist = max(maxdist, dist);
        }
        double maxt = maxdist / V;

        vector<double> P;
        for (int i = 0; i < N; i++) {
            P.push_back((DIR[i] ? POS[i] + maxt*V : POS[i] - maxt*V));
        }
        sort(P.begin(), P.end());

        int i;
        for (i = 0; i < N; i++) {
            if (abs(P[i]) < 1e-5 || abs(L-P[i]) < 1e-5) break;
        }
        printf("%13.2f %s\n", floor(maxt * 100.0)/100.0, NAME[i].c_str());
    }
}
