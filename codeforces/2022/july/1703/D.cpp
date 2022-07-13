#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  map<string, bool> m;
  vector<string> v;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    m[s] = true;
    v.push_back(s);
  }

  vector<bool> answer;
  for (const auto& key : v) {
    bool exist = false;
    for (int i = 1; i < key.size(); ++i) {
      string left = key.substr(0, i);
      string right = key.substr(i);
      if (m.count(left) && m.count(right)) {
        exist = true;
        break;
      }
    }
    answer.push_back(exist);
  }
  for(const auto& val : answer)
    cout << val;
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