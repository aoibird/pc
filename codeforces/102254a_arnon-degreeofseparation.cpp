#include <iostream>
#define MAXVERT 2000
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int **matrix;
  matrix = new int*[n];
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n];
    for (int j = 0; j < n; j++) {
      matrix[i][j] = MAXVERT;
    }
  }
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    matrix[a-1][b-1] = 1;
    matrix[b-1][a-1] = 1;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
          matrix[i][j] = matrix[i][k] + matrix[k][j];
        }
      }
    }
  }


  int max = 0;
  bool connect;
  for (int i = 0; i < n; i++) {
    connect = false;
    for (int j = 0; j < n; j++) {
      //cout << matrix[i][j] << " ";
      if (matrix[i][j] != MAXVERT && matrix[i][j] > max)
        max = matrix[i][j];
      if (matrix[i][j] != MAXVERT) connect = true;
    }
    if (connect == false) break;
    //cout << "\n";
  }

  if (connect == false) {
    cout << "=]\n";
  }
  else {
    cout << "=] "<< max << "\n";
  }


}
