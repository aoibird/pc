#include <iostream>
#include <vector>
#define MAXN 45
using namespace std;

int n;

void swap(vector<int> *matrix, int i, int j)
{
  vector<int> temp = matrix[i];
  matrix[i] = matrix[j];
  matrix[j] = temp;
}

bool smaller(vector<int> *matrix, int i, int j)
{
  for (int k = n-1; k >= 0; k--) {
    if (matrix[i][k] == 0 && matrix[j][k] == 1) {
      return true;
    }
    else if (matrix[i][k] == 1 && matrix[j][k] == 0) {
      return false;
    }
    else {
      ;
    }
  }

  return false;
}

void trace(vector<int> *matrix)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main()
{
  // input
  cin >> n;
  vector<int> matrix[n];
  //int index[n];
  cin.ignore();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      matrix[i].push_back(c - '0');
    }
    //cin.ignore();
  }

  trace(matrix);

  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
    //for (int j = 0; j < n; j++) {
      if (smaller(matrix, j, j-1)) {
        //printf("smaller %d %d\n", j, j-1);
        swap(matrix, j, j-1);
        sum += 1;
      }
      trace(matrix);
    }
  }


  // output
  cout << sum << endl;
}
