// UVa 10905
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50+5;
// const int MAXC = 200;
string numbers[MAXN];
int N;

bool compare(string &a, string &b)
{
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] > b[i]) return true;
    }
    if (a.size() < b.size()) return true;
    else return false;
}


int main()
{
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        getchar();
        // printf("N = %d\n", N);
        // char str[MAXC];
        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
            getchar();
        }

        sort(numbers, numbers+N, compare);

        for (int i = 0; i < N; i++) {
            cout << numbers[i];
        }
        printf("\n");
    }
}
