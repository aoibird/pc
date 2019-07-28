#include <iostream>
#define MAXN 10000
using namespace std;

int a[MAXN];
int n;
int x;

void input()
{
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}

void lower_bound()
{
  int lb = -1, ub = n;

  while (ub - lb > 1) {
    int mid = (lb+ub)/2;
    if (a[mid] >= x) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);

}

void upper_bound()
{
  int lb = -1, ub = n;

  while (ub - lb > 1) {
    int mid = (lb+ub)/2;
    if (a[mid] > x) ub = mid;
    else lb = mid;
  }

  printf("%d\n", lb);

}


int main()
{
  input();
  lower_bound();
  upper_bound();
}
