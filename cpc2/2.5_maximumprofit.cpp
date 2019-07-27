#include <iostream>
static const int MAX = 200000;

using namespace std;

int a[MAX];

int maxprofit(int a[], int len)
{
  int max = -2000000000;
  int min = a[0];

  for (int i = 1; i < len; i++) {
    if (a[i] - min > max) max = a[i] - min;

    if (a[i] < min) min = a[i];
  }

  return max;
}

int main()
{
  int len;
  cin >> len;
  for (int i = 0; i < len; i++) {
    cin >> a[i];
  }

  int best = maxprofit(a, len);

  cout << best << endl;
}
