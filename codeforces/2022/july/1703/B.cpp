#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  map<char, int> m;

  for (const auto &letter : s) {
    ++m[letter];
  }
  int result = 0;
  for (const auto &[key, value] : m) {
    result += value + 1;
  }
  cout << result << endl;
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