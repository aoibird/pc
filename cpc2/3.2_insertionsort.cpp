#include <iostream>
static const int MAXLEN = 100;
//static const int MAXVAL = 1000;

using namespace std;

int a[MAXLEN];
int n;

void trace()
{
    cout << a[0];
    for (int i = 1; i < n; i++) {
      cout << " " << a[i];
    }
    cout << endl;
}

void insertionsort(int a[], int n)
{
  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j;
    for (j = i - 1; j >= 0 && a[j] > v; j--) {
      a[j+1] = a[j];
    }
    a[j+1] = v;

    trace();
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  trace();
  insertionsort(a, n);

}
