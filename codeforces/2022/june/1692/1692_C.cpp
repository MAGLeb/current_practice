#include <bits/stdc++.h>

using namespace std;

void solve() {
  int cells = 0;
  int prev;
  char curr;
  pair<int, int> result = {-1, -1};
  for (int i = 0; i < 8; ++i) {
    prev = cells;
    cells = 0;
    int column;
    for (int j = 0; j < 8; ++j) {
      cin >> curr;
      if (curr == '#') {
        ++cells;
        column = j;
      }
    }
    if (prev == 2 and cells == 1 and result == make_pair(-1, -1))
      result = {i + 1, column + 1};
  }
  cout << result.first << ' ' << result.second << endl;

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