#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(200, 0);
  v[0] = 1;

  for (int i = 2; i < n + 1; i++) {
    vector<int> a(200, 0);
    for (int j = 0; j < v.size(); j++) {
      int rest = v[j] * i;
      int k = j;
      while (rest != 0) {
        rest += a[k];
        a[k++] = rest % 10;
        rest /= 10;
      }
    }
    v = a;
  }

  uint64_t res = 0;
  for (auto val : v) {
    res += val;
    cout << val << ' ';
  }
  cout << endl;
  cout << res << endl;
}