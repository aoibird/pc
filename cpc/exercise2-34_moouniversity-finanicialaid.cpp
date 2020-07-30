// POJ 2010
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

const int MAXC = 1e5+10;
PII CA[MAXC]; // (score, finanicial aid)
int N, C, F;

bool cmp_score(const PII &a, const PII &b) { return a.first > b.first; }
bool cmp_aid(const PII &a, const PII &b) { return a.second < b.second; }

priority_queue<PII, vector<PII>, greater<PII> > SEL; // score_i < score_j
priority_queue<PII, vector<PII>, greater<PII> > CAN; // aid_i < aid_j
vector<PII> temp;


void solve()
{
    int sum = 0;
    sort(CA, CA+C, cmp_aid);
    for (int i = 0; i < N; i++) { SEL.push(CA[i]); sum += CA[i].second; }
    if (sum > F) { printf("-1\n"); return; }
    for (int i = N; i < C; i++) { CAN.push(PII(CA[i].second, CA[i].first)); }
    for (int i = 0; i < N/2; i++) { SEL.pop(); }
    // while (!CAN.empty()) {
    //     printf("(%d %d) ", CAN.top().first, CAN.top().second);
    //     CAN.pop();
    // }
    // printf("\n");
    temp.resize(0);
    while (!CAN.empty()) {
        PII cur = SEL.top(); int cur_score = cur.first, cur_aid = cur.second;
        PII tar = CAN.top(); int tar_score = tar.second, tar_aid = tar.first;
        // printf("current: (%d %d) target: (%d %d)\n",
        //        cur_score, cur_aid, tar_score, tar_aid);
        if (tar_score < cur_score) {
            CAN.pop();
        }
        else if (tar_score >= cur_score && sum - cur_aid + tar_aid <= F) {
            SEL.pop(); SEL.push(PII(tar_score, tar_aid)); CAN.pop();
            sum = sum - cur_aid + tar_aid;
            for (int i = 0; i < temp.size(); i++) CAN.push(temp[i]);
            temp.resize(0);
        }
        else { CAN.pop(); temp.push_back(tar); }
    }
    printf("%d\n", SEL.top().first);
}

int main()
{
    while (scanf("%d%d%d", &N, &C, &F) == 3) {
        for (int i = 0; i < C; i++) scanf("%d%d", &CA[i].first, &CA[i].second);
        while (!SEL.empty()) SEL.pop();
        while (!CAN.empty()) CAN.pop();
        solve();
    }
}
