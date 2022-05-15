#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int m, k;
    cin >> m >> k;

    pair<int, int> mN(10, 10);
    vector<pair<int, int>> v;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < k; j++) {
        char c;
        cin >> c;
        if (c == 'R') {
          auto p = make_pair(i, j);
          if (p.first + p.second < mN.first + mN.second)
            mN = p;
          v.push_back(p);
        }
      }
    }

//    cout << mN.first << ' ' << mN.second << endl;
//
//    cout << "vector: ";
//    for (auto p : v)
//      cout << p.first << ' ' << p.second;
//    cout << endl;

    string res = "YES";
    for (auto p : v) {
      if (mN.first > p.first || mN.second > p.second) {
        res = "NO";
        break;
      }
    }
    cout << res << endl;
  }
}