#include <bits/stdc++.h>

using namespace std;

int next_number(int value, string &command) {
  int up = 0, down = 0;
  for (const auto &c : command) {
    if (c == 'U')
      ++up;
    else
      ++down;
  }
  int shift = up - down;
  shift %= 10;
  value -= shift;
  if (value < 0)
    value += 10;
  else if (value > 9)
    value -= 10;
  return value;
}

void solve() {
  int n;
  cin >> n;
  vector<int> digits(n);
  for (int i = 0; i < n; ++i) {
    cin >> digits[i];
  }

  for (int i = 0; i < n; ++i) {
    int m;
    string s;
    cin >> m >> s;
    digits[i] = next_number(digits[i], s);;
  }

  for (const auto &digit : digits) {
    cout << digit << ' ';
  }
  cout << endl;

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