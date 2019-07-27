#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<int> gaps;


void insertion_sort(int a[], int n, int off)
{
  for (int i = off; i < n; i++) { // i++ ? i += off ?
    int curr = a[i];
    int j;
    for (j = i - off; j >= 0 && a[j] > curr; j -= off) {
        a[j+off] = a[j];
        cnt++;
    }
    a[j+off] = curr;
  }
}

void shell_sort(int a[], int n)
{
  for (int h = 1; ; ) {
    if (h > n) break;
    gaps.push_back(h);
    h = 3*h + 1;
  }

  for (int i = gaps.size()-1; i >= 0; i--) {
    int off = gaps[i];
    insertion_sort(a, n, off);
  }

}

int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  shell_sort(a, n);
  int g = gaps.size();
  cout << g << endl;
  for (int i = g-1; i >= 0; i--) {
    cout << gaps[i];
    if (i != 0) cout << " ";
    else cout << "\n";
  }
  cout << cnt << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
}
