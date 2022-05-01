#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  int counter = 1;
  cin >> n;
  vector<vector<int>> v;

  while (n--) {
    vector<int> inter(counter);
    for (int i = 0; i < counter; i++) {
      cin >> inter[i];
    }
    counter++;
    v.push_back(inter);
  }

  for (int i = 1; i < v.size(); i++) {
    vector<int> &curr = v[i];
    for (int j = 0; j < curr.size(); j++) {
      vector<int> &prev = v[i - 1];
      if (j == 0)
        curr[j] = prev[j] + curr[j];
      else if(j == prev.size())
        curr[j] = prev[j - 1] + curr[j];
      else
        curr[j] = max(prev[j], prev[j - 1]) + curr[j];
    }
  }

  vector<int> &last_row = v.back();
  cout << *max_element(begin(last_row), end(last_row));
}