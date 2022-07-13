#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<int, int> f, int value) {
  return f.first < value;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 1; i < n + 1; ++i) {
    int inter;
    cin >> inter;
    if (i > inter)
      v.push_back({inter, i});
  }

  sort(begin(v), end(v));

  uint64_t answer = 0;
  for(const auto& [val, index] : v) {
    auto it = lower_bound(v.begin(), v.end(), index + 1, comparator);
    answer += distance(it, v.end());
  }
  cout << answer << endl;

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