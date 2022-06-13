#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  set<pair<int, int>> s;
  vector<int> v;
  for(int i = 0; i < n; ++i) {
    int inter;
    cin >> inter;
    s.insert({inter % k, i});
    v.push_back(inter);
  }

  uint64_t result = 0;
  auto start = begin(s);
  auto last = --end(s);
  while(true) {
    auto it_pair = s.lower_bound({k - last->first, -1});
    if(it_pair == last or it_pair == end(s)) {
      result += (v[start->second] + v[last->second]) / k;
      s.erase(start);
    } else {
      result += (v[it_pair->second] + v[last->second]) / k;
      s.erase(it_pair);
    }

    s.erase(--end(s));
    if (s.size() == 0)
      break;
    start = begin(s);
    last = --end(s);
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