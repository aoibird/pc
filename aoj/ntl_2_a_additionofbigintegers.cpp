// AOJ NTL_2_A Addition of Big Integers
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
typedef unsigned int uint;
typedef pair<int,int> PII;

const int MAXN = 100000+5;
string ST1, ST2;
vector<int> D1, D2, D3;
int S1, S2, S3;

void print_array(vector<int> a)
{
    for (uint i = 0; i < a.size(); i++) printf("%d%c", a[i], i==a.size()-1?'\n':' ');
}

int compare(vector<int> a, vector<int> b)
{
    // if a > b return 1, if a < b return 0, if a == b return 0
    if (a.size() > b.size()) { return 1; }
    else if (a.size() < b.size()) { return -1; }
    else {
        for (int i = a.size()-1; i >= 0; i--) {
            if (a[i] > b[i]) { return 1; }
            else if (a[i] < b[i]) { return -1; }
            else { ; }
        }
        return 0;
    }
}

void add(vector<int> a, vector<int> b, vector<int> &c)
{
    int to = max(a.size(), b.size());
    int carry = 0;
    for (int i = 0; i < to; i++) {
        int sum = (i < (int) a.size() ? a[i] : 0) + (i < (int) b.size() ? b[i] : 0) + carry;
        carry = sum >= 10 ? 1 : 0;
        sum = (sum > 10) ? sum - 10 : sum;
        c.push_back(sum % 10);
    }
    if (carry != 0) { c.push_back(carry); }
}

void substract(vector<int> a, vector<int> b, vector<int> &c)
{
    int to = max(a.size(), b.size());
    int borrow = 0;
    for (int i = 0; i < to; i++) {
        int sub = (i < (int) a.size() ? a[i] : 0) - (i < (int) b.size() ? b[i] : 0) - borrow;
        borrow = (sub < 0) ? 1 : 0;
        sub = (sub < 0) ? sub + 10 : sub;
        c.push_back(sub % 10);
    }
}

void solve()
{
    if (S1 == S2) {
        S3 = S1; add(D1, D2, D3);
    } else {
        int comp = compare(D1, D2);
        if (comp == 1) { S3 = S1; substract(D1, D2, D3); }
        else if (comp == -1) { S3 = S2; substract(D2, D1, D3); }
        else { S3 = 1; D3.push_back(0); }
    }
}

int main()
{
    while((cin >> ST1 >> ST2)) {
        // printf("%s %s\n", ST1.c_str(), ST2.c_str());
        D1.clear(); D2.clear(); D3.clear();
        S1 = S2 = S3 = 1;

        for (int i = ST1.size()-1; i >= 0; i--) {
            if (ST1[i] >= '0' && ST1[i] <= '9') {
                // printf("%c\n", ST1[i]);
                D1.push_back(ST1[i] - '0');
            } else {
                S1 = -1;
            }
        }
        for (int i = ST2.size()-1; i >= 0; i--) {
            if (ST2[i] >= '0' && ST2[i] <= '9') {
                // printf("%c\n", ST1[i]);
                D2.push_back(ST2[i] - '0');
            } else {
                S2 = -1;
            }
        }

        solve();

        // print_array(D1);
        // print_array(D2);
        // print_array(D3);
        if (S3 == -1) printf("-");
        int fr = D3.size()-1;
        while (D3[fr] == 0 && fr > 0) { fr--; }
        for (int i = fr; i >= 0; i--) {
            printf("%d", D3[i]);
        }
        printf("\n");
        // printf("\n");
    }
}
