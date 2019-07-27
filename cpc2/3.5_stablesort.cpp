#include <iostream>
#define MAXN 40
using namespace std;

string a1[MAXN];
string a2[MAXN];
int n;

void trace()
{
  for (int i = 0; i < n; i++) {
    cout << a1[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << a2[i] << " ";
  }
  cout << "\n";
}

void input()
{
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    a1[i] = a2[i] = s;
  }

  //trace();
}

void swap(string *a, int i, int j)
{
  string s = a[i];
  a[i] = a[j];
  a[j] = s;
}

bool smaller(string s, string t)
{
  //if (s[0] < t[0]) return true;
  if (s[1] < t[1]) return true;
  else return false;
}

void bubblesort()
{
  for (int i = 0; i < n-1; i++) {
    for (int j = n-1; j > i; j--) {
      if (a1[j][1] < a1[j-1][1]) {
        swap(a1, j, j-1);
      }
    }
  }
}

void selectionsort()
{
  for (int i = 0; i < n-1; i++) {
    int sel = i;
    for (int j = i+1; j < n; j++) {
      if (a2[j][1] < a2[sel][1]) sel = j;
    }

    if (sel != i) swap(a2, sel, i);
  }
}

bool isstable()
{
  for (int i = 0; i < n; i++) {
    if (a2[i] != a1[i]) return false;
  }
  return true;
}

void output()
{
  for (int i = 0; i < n; i++) {
    cout << a1[i];
    if (i != n-1) cout << " ";
    else cout << "\n";
  }
  cout << "Stable\n";
  for (int i = 0; i < n; i++) {
    cout << a2[i];
    if (i != n-1) cout << " ";
    else cout << "\n";
  }
  bool stable = isstable();
  if (stable) cout << "Stable\n";
  else cout << "Not stable\n";
}

int main()
{
  input();
  bubblesort();
  selectionsort();
  output();
}
