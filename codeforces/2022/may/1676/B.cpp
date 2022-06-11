#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int mN = numeric_limits<int>::max();
    int k;
    cin >> k;
    vector<int> v(k);

    for (int i = 0; i < k; i++) {
      cin >> v[i];
      if (v[i] < mN)
        mN = v[i];
    }

    uint64_t res = 0;
    for (int i = 0; i < k; i++)
      res += max(0, v[i] - mN);

    cout << res << endl;
  }
}