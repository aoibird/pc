// Luogu 1601 A+B Problem（高精）
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

const int MAXL = 500+10;
char A[MAXL], B[MAXL];

struct BigInt {
    static const int MOD = 1e9;
    static const int WIDTH = 9;
    vector<ll> digits;
    BigInt(int num=0) { digits.clear(); digits.push_back(0); }
    BigInt(const string &s) { *this = s; }
    BigInt& operator=(const string &s) {
        digits.clear();
        int x, len = (s.length()-1)/WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = s.length() - i*WIDTH;
            int start = max(0, end-WIDTH);
            sscanf(s.substr(start, end-start).c_str(), "%d", &x);
            digits.push_back(x);
        }
        return *this;
    }
    BigInt operator+(BigInt &a) {
        BigInt c; c.digits.clear();
        ll carry = 0;
        for (int i = 0; i<a.digits.size()||i<digits.size()||carry!=0; i++) {
            ll x = (i < a.digits.size()) ? a.digits[i] : 0;
            ll y = (i < digits.size()) ? digits[i] : 0;
            ll z = x + y + carry;
            carry = z / MOD;
            c.digits.push_back(z % MOD);
        }
        return c;
    }
    void trim() {
        while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
    }
    void print() {
        trim();
        printf("%lld", digits.back());
        for (int i = digits.size()-2; i >= 0; i--) {
            printf("%09lld", digits[i]);
        }
    }
};

int main()
{
    while (scanf("%s%s", A, B) == 2) {
        string sa = A, sb = B;
        BigInt a = sa, b = sb;
        BigInt c = a + b;
        c.print(); printf("\n");
    }
}
