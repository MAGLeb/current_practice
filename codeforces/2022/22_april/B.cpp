#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int k;
    cin >> k;
    vector<int> v;

    while (k--) {
      int val;
      cin >> val;
      v.push_back(val);
    }

    int diff = 0;
    for (int i = 1; i < v.size(); ++i) {
      diff += v[i] - v[i - 1];
    }

    if (diff <= v.size() + 1 && diff >= v.size() - 1)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
}