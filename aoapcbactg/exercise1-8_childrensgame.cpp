// UVa 10905
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 50+5;
string numbers[MAXN];
int N;

bool compare(string &a, string &b)
{
    string c = a + b;
    string d = b + a;
    if (c > d || (c == d && a.size() > b.size())) return true;
    else return false;
}


int main()
{
    while (scanf("%d", &N) == 1 && N) {
        getchar();
        for (int i = 0; i < N; i++) cin >> numbers[i];

        sort(numbers, numbers+N, compare);

        for (int i = 0; i < N; i++) cout << numbers[i];
        printf("\n");
    }
}
