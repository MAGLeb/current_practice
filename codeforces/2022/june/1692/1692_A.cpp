#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<int> v(4);
  for(int i = 0; i < 4; ++i)
    cin >> v[i];

  int result = 0;
  for(int i = 1; i < 4; ++i)
    if (v[i] > v[0])
      ++result;

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