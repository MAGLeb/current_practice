#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int k;
    cin >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++)
      cin >> v[i];

    int64_t res = 0;
    for(int i = v.size() - 1; i > 0; i--) {
      if (v[i] == 0) {
        res = -1;
        break;
      }
      for(int j = i - 1; j >= 0; j--) {
        while(v[j] >= v[i]) {
          res += 1;
          v[j] /= 2;
        }
      }
    }

    cout << res << endl;
  }
}