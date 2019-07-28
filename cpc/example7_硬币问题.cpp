#include <iostream>
using namespace std;

int value[6] = {1, 5, 10, 50, 100, 500};
int cap[6];

int coin(int amount)
{
  int total = 0;
  for (int i = 5; i >= 0 && amount != 0; i--) {
    int v = value[i];
    int t = min(amount / v, cap[i]);
    total += t;
    amount = amount - t * v;
  }
  return total;
}

int main()
{
  int amount;
  cin >> amount;
  int c;
  for (int i = 0; i < 6; i++) {
    cin >> cap[i];
  }
  cout << coin(amount) << endl;

}
