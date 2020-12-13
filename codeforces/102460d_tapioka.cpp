// Codeforces 102460 D Tapioka
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string words[3];
bool target[3];
int cnt;

int main()
{
    for (int i = 0; i < 3; i++) {
        cin >> words[i];
        if (words[i] == "bubble" || words[i] == "tapioka") {
            target[i] = true;
            cnt++;
        }
    }
    if (cnt == 3) printf("nothing\n");
    else {
        bool first = true;
        for (int i = 0; i < 3; i++) {
            if (!target[i]) {
                if (first) first = false;
                else printf(" ");
                cout << words[i];
            }
        }
        printf("\n");
    }
}
