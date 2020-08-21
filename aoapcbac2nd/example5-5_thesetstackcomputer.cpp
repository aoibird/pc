#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;

typedef set<int> SI;
map <SI, int> ids;
vector<SI> sets;
stack<int> s;

int getid(SI x)
{
  if (ids.count(x) != 0) return ids[x];
  else {
    sets.push_back(x);
    return ids[x] = sets.size() - 1;
  }
}

void execute(string op)
{
  if (op == "PUSH") {
    s.push(getid(SI()));
  }
  else if (op == "DUP") {
    s.push(s.top());
  }
  else {
    SI x1 = sets[s.top()]; s.pop();
    SI x2 = sets[s.top()]; s.pop();
    SI x;
    if (op == "UNION")
      set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
    else if (op == "INTERSECT")
      set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
    else if (op == "ADD") {
      x = x2;
      x.insert(getid(x1));
    }
    else ;
    s.push(getid(x));
  }
  cout << sets[s.top()].size() << endl;
}

int main()
{
  int rnd;
  cin >> rnd;
  for (int i = 0; i < rnd; i++) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      string op;
      cin >> op;
      execute(op);
    }
    cout << "***" << endl;
  }
}
