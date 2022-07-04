#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  bool change = false;
  if (n < m) {
    int inter = n;
    n = m;
    m = inter;
    change = true;
  }
  vector<vector<int>> matrix(n, vector<int>(m, -1));

  matrix[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int opposite;
      if (matrix[i][j] == 0) {
        opposite = 1;
      } else {
        opposite = 0;
      }
      int state = 0;
      vector<pair<int, int>> shift = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
      for (auto [i_, j_] : shift) {
        i_ += i;
        j_ += j;
        if (i_ < 0 || i_ >= n || j_ < 0 || j_ >= m) {
          continue;
        } else if (matrix[i_][j_] == -1) {
          if (state < 2) {
            matrix[i_][j_] = opposite;
          } else {
            matrix[i_][j_] = matrix[i][j];
          }
        }
        if (matrix[i_][j_] != matrix[i][j]) {
          ++state;
        }
      }
    }
  }

  if (change) {
    vector<vector<int>> transpose(m, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        transpose[j][i] = matrix[i][j];
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << transpose[i][j] << ' ';
      }
      cout << endl;
    }
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << matrix[i][j] << ' ';
      }
      cout << endl;
    }
  }

  return;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;

  while (n--) {
    solve();
  }

  return 0;
}