#include <iostream>
#define MAXN 105
using namespace std;

int a[MAXN];
int n;
int sw;

void input()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

}

void swap(int i, int j)
{
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void selectionsort()
{
  for (int i = 0; i < n-1; i++) {
    int sel = i;
    int j;
    for (j = i+1; j < n; j++) {
      if (a[sel] > a[j]) {
        sel = j;
      }
    }

    if (sel != i) {
      swap(sel, i);
      sw++;
    }
  }
}

void output()
{
  cout << a[0];
  for (int i = 1; i < n; i++) {
    cout << " " << a[i];
  }
  cout << "\n" << sw << "\n";
}

int main()
{
  input();
  selectionsort();
  output();
}
