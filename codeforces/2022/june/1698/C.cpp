#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> m;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ++m[v[i]];
  }

  bool wrong = false;

  for(const auto& [key_1, value_1] : m) {
    map<int, int> prev_keys;
    ++prev_keys[key_1];

    for(const auto& [key_2, value_2] : m) {
      if(prev_keys[key_2] == value_2) {
        continue;
      }

      ++prev_keys[key_2];

      for(const auto& [key_3, value_3] : m) {
        if(prev_keys[key_3] == value_3) {
          continue;
        }

        ++prev_keys[key_3];
        int inter = key_1 + key_2 + key_3;
        if(m.count(inter) == 0) {
          wrong = true;
          break;
        }
        --prev_keys[key_3];
      }
      --prev_keys[key_2];
      if(wrong)
        break;
    }
    if(wrong)
      break;
  }

  if(wrong)
    cout << "NO"s << endl;
  else
    cout << "YES"s << endl;
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