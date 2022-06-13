#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<bool> v(201, false);
  vector<int> b;
  int n;
  cin >> n;

  while(n--) {
    int inter;
    cin >> inter;
    v[inter] = true;
    b.push_back(inter);
  }

  vector<int> result;
  bool find_next = false;
  for(const auto& b_val : b) {
    find_next = false;
    result.push_back(b_val);
    for(int i = b_val + 1; i < v.size(); ++i) {
      if(i > b.size() * 2)
        break;
      if(!v[i]) {
        v[i] = true;
        result.push_back(i);
        find_next = true;
        break;
      }
    }
    if (!find_next) {
      break;
    }
  }

  if(find_next) {
    for(const auto& val : result)
      cout << val << ' ';
    cout << endl;
  } else
    cout << -1 << endl;

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