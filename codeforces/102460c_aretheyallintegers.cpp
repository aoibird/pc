// Codeforces 102460 C Are They All Integers?
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 50+4;
int A[MAXN];
int n;

int main()
{
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && i != k && j != k)
                        if ((A[i] - A[j]) % A[k] != 0) {
                            printf("no\n"); return 0;
                        }
                }
            }
        }
        printf("yes\n");
    }
}
