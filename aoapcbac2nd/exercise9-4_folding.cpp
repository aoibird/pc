// UVa 1630
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int MAXN = 100+10;

char S[MAXN];
string SS;
int N;
string dp[MAXN][MAXN];
char buff[MAXN*2];

void get_pos(string &s, int &p, int &q, int &l)
{
    p = q = l = -1;
    stack<char> st;
    while(!st.empty()) st.pop();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            if (st.empty()) { p = i; }
            st.push('(');
        }
        else if (s[i] == ')') {
            st.pop();
            if (st.empty()) { q = i; break; }
        }
        else ;
    }
    l = q - p + 1;
}

bool isrepeat(string &s, int f, int t, int r)
{
    int l = t - f + 1;
    if (l % r != 0) return false;

    for (int i = 0; i + r <= l; i+=r) {
        if (s.substr(f+i, r) != s.substr(f, r)) return false;
    }
    return true;
}

string fold(int f, int t)
{
    int l = t - f + 1;

    if (dp[f][t] != "") return dp[f][t];
    if (l <= 4) return SS.substr(f, l);

    for (int i = 1; i <= 3; i++) {
        if (isrepeat(SS, f, t, i)) {
            sprintf(buff, "%d(%s)", l/i, SS.substr(f, i).c_str());
            return dp[f][t] = string(buff);
        }
    }

    string res = SS.substr(f, t-f+1), s, a, b, asub, bsub;
    int p1, p2, q1, q2, l1, l2, c1, c2;
    for (int i = f; i <= t-1; i++) {
        a = fold(f, i); b = fold(i+1, t);
        get_pos(a, p1, q1, l1); get_pos(b, p2, q2, l2);
        c1 = (p1 == -1) ? 0 : atoi(a.substr(0, p1).c_str());
        c2 = (p2 == -1) ? 0 : atoi(b.substr(0, p2).c_str());
        asub = (p1 == -1) ? "" : a.substr(p1, l1);
        bsub = (p2 == -1) ? "" : b.substr(p2, l2);

        if (p1 == -1 && p2 == -1) {        // ...  <-> ...
            if (a == b) s = "2(" + a + ")";
            else s = a + b;
        }
        else if (p1 != -1 && p2 == -1) {   // ...x(...)... <-> ...
            if (c1 != 0 && q1 == a.size()-1 && "("+b+")" == asub) {
                sprintf(buff, "%d", c1+1);
                s = string(buff) + asub;
            }
            else s = a + b;
        }
        else if (p1 == -1 && p2 != -1) {   // ... <-> ...x(...)...
            if (c2 != 0 && q2 == b.size()-1 && "("+a+")" == bsub) {
                sprintf(buff, "%d", c2+1);
                s = string(buff) + bsub;
            }
            else s = a + b;
        }
        else {                             // ...x(...)... <-> ...x(...)...
            if (c1 != 0 && c2 != 0 && q1 == a.size()-1 && q2 == b.size()-1) {
                // x(...) <-> x(...)
                if (asub == bsub) {
                    sprintf(buff, "%d", c1 + c2);
                    s = string(buff) + asub;
                }
                else s = a + b;
            }
            else if (a == b) s = "2(" + a + ")";
            else s = a + b;
        }

        if (s.size() < res.size()) { res = s; }
        // printf("%s %s -> %s (%d %d %d)\n",a.c_str(),b.c_str(),s.c_str(),
        //        f,t,i);
    }
    return dp[f][t] = res;
}

void solve()
{
    N = strlen(S);
    SS = S;
    string s = fold(0, N-1);
    printf("%s\n", s.c_str());
}

int main()
{
    while (scanf("%s", S) == 1) {
        memset(dp, 0, sizeof(dp));
        solve();
    }
}
