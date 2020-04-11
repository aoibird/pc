#include <iostream>
#include <vector>
#define MAX 1000000000
using namespace std;

vector<int> v;
int n, x, d;
int cnt = 0;

void subset(int k, int a[])
{
  if (k == n) {
    int min = MAX, max = 0;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
      if (a[v[i]] < min) min = a[v[i]];
      if (a[v[i]] > max) max = a[v[i]];
      sum += a[v[i]];
    }
    // for (int i = 0; i < v.size(); i++) {
    //   printf("%d ", v[i]);
    // }
    // printf("\n");
    // printf("%d %d %d\n", sum, min, max);
    if (sum >= x && (max - min) <= d && (max - min) >= 0) {
      cnt += 1;
    }
  }
  else {
    subset(k+1, a);
    v.push_back(k);
    subset(k+1, a);
    v.pop_back();
  }

}

int main()
{
  cin >> n >> x >> d;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  subset(0, a);

  cout << cnt << "\n";
}
