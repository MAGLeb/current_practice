#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int k, m;
    cin >> k;
    int mod_1, mod_2;
    cin >> mod_1 >> mod_2;
    mod_1 %= 2;
    mod_2 %= 2;

    string res = "YES";
    m = 1;
    while (++m != k) {
      int val;
      cin >> val;
      if (m % 2 == 0) {
        if (val % 2 != mod_1)
          res = "NO";
      } else {
        if (val % 2 != mod_2)
          res = "NO";
      }
    }

    cout << res << endl;
  }
}