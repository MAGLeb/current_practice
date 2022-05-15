#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, q;
  cin >> n >> q;

  vector<int> x(n + 1, 0);
  vector<int> y(n + 1, 0);
  set<int> rows;
  set<int> cols;

  for (int i = 1; i < n + 1; i++) {
    rows.insert(i);
    cols.insert(i);
  }

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int x_, y_;
      cin >> x_ >> y_;
      if (x[x_]++ == 0)
        rows.erase(x_);
      if (y[y_]++ == 0)
        cols.erase(y_);
    } else if (t == 2) {
      int x_, y_;
      cin >> x_ >> y_;
      x[x_] -= 1;
      if (x[x_] == 0)
        rows.insert(x_);
      y[y_] -= 1;
      if (y[y_] == 0)
        cols.insert(y_);
    } else {
      int x_1, x_2, y_1, y_2;
      cin >> x_1 >> y_1 >> x_2 >> y_2;
      string res = "No";

      auto it = rows.lower_bound(x_1);
      if (it == end(rows) || *it > x_2)
        res = "Yes";
      else {
        it = cols.lower_bound(y_1);
        if (it == end(cols) || *it > y_2)
          res = "Yes";
      }
      cout << res << endl;
    }
  }
}
