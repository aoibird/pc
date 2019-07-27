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

void swap(int x, int y)
{
  int temp = a[x];
  a[x] = a[y];
  a[y] = temp;
}

void bubblesort()
{
  for (int i = 0; i < n; i++) {
    for (int j = n-1; j > i; j--) {
      if (a[j] < a[j-1]) {
        swap(j, j-1);
        sw += 1;
      }
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
  bubblesort();
  output();
}
