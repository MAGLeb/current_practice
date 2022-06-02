#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> res(n);

  for(int i = 0; i < n; i++) {
    cin >> v[i];
    res[i] = i;
  }

  int prev = v[0];
  for(int i = 1; i < n; i++) {
    if(v[i] == prev) {
      swap(res[i], res[i-1]);
    }
    prev = v[i];
  }

  string result;
  if(v.size() == 1) {
    result = "-1";
  } else {
    for(int i = 0; i < n; i++) {
      if(i == res[i]) {
        result = "-1";
        break;
      }
      result += to_string(res[i] + 1) + ' ';
    }
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