#include <bits/stdc++.h>

using namespace std;

void solve(set<map<int, int>> s) {
  int n;
  map<int, int> m_;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int inter;
    cin >> inter;
    string s = to_string(inter);
    ++m_[(int)s[s.size() - 1] - 48];
  }

//  for(const auto& p : m_)
//    cout << p.first << ' ' << p.second << endl;

  bool result = false;
  for (const auto &m_s : s) {
    bool res = true;
    for (const auto &p : m_s) {
      if (m_[p.first] < p.second)
        res = false;
    }
    if(res) {
      result = res;
      break;
    }
  }

  if(result)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

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

  set<map<int, int>> s;
  vector<int> v({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i; j < v.size(); ++j) {
      for (int k = j; k < v.size(); ++k) {
        int curr = v[i] + v[j] + v[k];
        string curr_string = to_string(curr);
        if (curr_string[curr_string.size() - 1] == '3') {
          map<int, int> m;
          ++m[i];
          ++m[j];
          ++m[k];
          s.insert(m);
        }
      }
    }
  }

  while (n--) {
    solve(s);
  }

  return 0;
}