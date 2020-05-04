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

// const int MAXN = 50+5;
const int MAXC = 100;
vector<string> numbers;
char S[MAXC];
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
        // while (!numbers.empty()) numbers.pop_back();
        numbers.clear();
        getchar();
        // printf("N = %d\n", N);
        string number;
        for (int i = 0; i < N; i++) {
            int ch; int t = 0;
            // while ((ch = getchar()) == ' ') ;
            while (isdigit(ch = getchar())) { S[t++] = ch; }
            S[t] = '\0';
            // while ((ch = getchar()) == ' ') ;
            number = S;
            numbers.push_back(number);
        }

        sort(numbers.begin(), numbers.end(), compare);

        for (int i = 0; i < N; i++) {
            cout << numbers[i];
        }
        printf("\n");
    }
}
