#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int m, a = -1, b = -1, c, d, val;
    vector<int> f;
    vector<int> s;
    cin >> m;

    for (int i = 0; i < m; i++) {
      cin >> val;
      if (a == -1 && val == '*')
        a = i;
      if (val == '*')
        c = i;
      f[i] = val;
    }

    for (int i = 0; i < m; i++) {
      cin >> val;
      if (b == -1 && val == '*')
        b = i;
      if (val == '*')
        d = i;
      s[i] = val;
    }

    int res = 0;
    if (a > b)
      a, b, c, d = b, a, d, c;

    while (a < c) {
      if (f[a] == '*')
        res += 1;
      if (s[a] == '*')
        res += 1;
    }
  }
}