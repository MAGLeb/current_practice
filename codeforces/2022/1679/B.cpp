#include <bits/stdc++.h>

using namespace std;

int main() {
  uint64_t n, k;
  cin >> n >> k;
  vector<int> v(n);
  vector<bool> status(n, true);

  uint64_t current;
  uint64_t sm = 0;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sm += v[i];
  }

  while (k--) {
    int t;
    cin >> t;

    if (t == 1) {
      int index, value;
      cin >> index >> value;
      index--;
      if (!status[index]) {
        status[index] = true;
        sm -= current;
      } else
        sm -= v[index];

      v[index] = value;
      sm += v[index];
    } else {
      status = vector<bool>(n, false);
      cin >> current;
      sm = current * n;
    }

    cout << sm << endl;
  }
}